class MyQueue {
private: 
    std::stack<int> st1;
    std::stack<int> st2;
public:
    MyQueue() {}
    
    void push(int x) {
        st2.push(x);
    }
    
    int pop() {
        if(st1.empty()) {
            while(!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }
        }
        int val = st1.top();
        st1.pop();
        return val;
    }
    
    int peek() {
        if(st1.empty()) {
            while(!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }
        }
        return st1.top();
    }
    
    bool empty() {
        return (st1.empty() && st2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */