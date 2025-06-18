class MinStack {
public:

    stack<int> stk;
    stack<int> min_stk;

    MinStack() {
    }
    
    void push(int val) {
        stk.push(val);
        if(min_stk.empty() || val <= min_stk.top()) {
            min_stk.push(val);
        }
    }
    
    void pop() {
        if(stk.empty()) return;
        if(stk.top() == min_stk.top()) {
            min_stk.pop();
        }
        stk.pop();
    }
    
    int top() {
        if(!stk.empty()) return stk.top();
        return -1;
    }
    
    int getMin() {
        if(!min_stk.empty()) return min_stk.top();
        return -1;
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