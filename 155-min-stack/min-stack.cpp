class MinStack {
public:

    long long mini = INT_MAX;
    stack<long long> st;

    MinStack() {}
    
    void push(int val) {
        if(st.empty()) {
            mini = val;
            st.push(val);
        }

        else {
            if(val < mini) {
                st.push(2LL*val - mini);
                mini = val;
            }

            else st.push(val);
        }
    }
    
    void pop() {
        if(st.top() < mini) {
            mini = 2LL*mini - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < mini) return mini;
        return st.top();
    }
    
    int getMin() {
        return mini;
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