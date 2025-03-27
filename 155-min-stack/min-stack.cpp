class Node {
    public:
        pair<int, int> data;
        Node* next;
        Node(int value, int mini, Node* next=nullptr): data({value, mini}), next(next) {}
};

class MinStack {
public:
    Node* head;
    int mini;

    MinStack() {
        head=nullptr;
        mini=INT_MAX;
    }
    
    void push(int val) {
        mini = min(mini, val);
        Node* newNode = new Node(val, mini);
        if(!head) head = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
    }
    
    void pop() {
        Node* prevHead = head;
        head = head->next;
        delete prevHead;
        if(!head) mini=INT_MAX;
        else mini = head->data.second;
    }
    
    int top() {
        return head->data.first;
    }
    
    int getMin() {
        return head->data.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */