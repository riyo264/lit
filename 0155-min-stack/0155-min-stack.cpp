class MinStack {
public:
    stack<pair<int, int>> st;
    int mini;
    MinStack() {

    }
    
    void push(int val) {
        if(st.empty()) {
            mini = val;
        }
        mini = min(mini, val);
        st.push({val, mini});
    }
    
    void pop() {
        if(!st.empty()) {
            st.pop();
        }
        if(!st.empty()) {
            mini = (st.top()).second;
        }
    }
    
    int top() {
        return (st.top()).first;
    }
    
    int getMin() {
        return (st.top()).second;
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