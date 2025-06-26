struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;

    Node() : key(-1), val(-1), prev(nullptr), next(nullptr) {}
    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:

    int max_capacity;
    int cache_size;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        max_capacity = capacity;
        cache_size = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void moveToTail(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        add(node);
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        cache.erase(node->key);
        delete node;
    }

    void add(Node* node) {
        tail->prev->next = node;
        node->prev = tail->prev;
        tail->prev = node;
        node->next = tail;
    }
    
    int get(int key) {
        if(cache.count(key) == 0) return -1;
        Node* recentNode = cache[key];
        moveToTail(recentNode);
        return recentNode->val;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            Node* recentNode = cache[key];
            recentNode->val = value;
            moveToTail(recentNode);
            return;
        }

        if(cache_size == max_capacity) {
            Node* nodeToDelete = head->next;
            remove(nodeToDelete);
            cache_size--; 
        }

        Node* newNode = new Node(key, value);
        add(newNode);
        cache[key] = newNode;
        cache_size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */