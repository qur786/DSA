class MinStack {
public:
    stack<long long> st;
    long long minValue;
    MinStack() {}

    void push(int value) {
        if (st.empty()) {
            st.push(value);
            minValue = value;
        } else if (value < minValue) {
            long long newValue = (long long)2 * value - minValue;
            st.push(newValue);
            minValue = value;
        } else {
            st.push(value);
        }
    }

    void pop() {
        long long value = st.top();
        st.pop();
        if (value < minValue) {
            minValue = (long long)2 * minValue - value;
        }
    }

    int top() { return st.top() < minValue ? minValue : st.top(); }

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