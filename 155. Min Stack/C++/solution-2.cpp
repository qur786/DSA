class MinStack {
public:
    long long minValue = 0;
    stack<long long> st;
    MinStack() {}

    void push(int value) {
        if (st.empty()) {
            st.push(value);
            minValue = value;
        } else if (minValue <= value)
            st.push(value);
        else {
            st.push((long long)2 * value - minValue);
            minValue = value;
        }
    }

    void pop() {
        if (st.top() < minValue)
            minValue = (long long)2 * minValue - st.top();
        st.pop();
    }

    int top() {
        if (st.top() > minValue)
            return st.top();
        return minValue;
    }

    int getMin() { return minValue; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */