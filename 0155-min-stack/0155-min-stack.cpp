class MinStack {
public:
    stack<int> st;
    stack<int> minSofar;
    int min  = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(minSofar.empty() || val<=minSofar.top())
        {
            minSofar.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        if(st.top() == minSofar.top())
        {
            minSofar.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSofar.top();
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