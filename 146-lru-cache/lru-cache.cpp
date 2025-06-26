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

    void update(Node* recentNode) {
        recentNode->prev->next = recentNode->next;
        recentNode->next->prev = recentNode->prev;
        tail->prev->next = recentNode;
        recentNode->prev = tail->prev;
        recentNode->next = tail;
        tail->prev = recentNode;
    }

    void remove(Node* nodeToDelete) {
        head->next = nodeToDelete->next;
        nodeToDelete->next->prev = head;
        cache.erase(nodeToDelete->key);
        delete nodeToDelete;
    }

    void add(Node* newNode) {
        tail->prev->next = newNode;
        newNode->prev = tail->prev;
        tail->prev = newNode;
        newNode->next = tail;
    }
    
    int get(int key) {
        if(cache.count(key) == 0) return -1;
        Node* recentNode = cache[key];
        update(recentNode);
        return recentNode->val;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            Node* recentNode = cache[key];
            recentNode->val = value;
            update(recentNode);
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