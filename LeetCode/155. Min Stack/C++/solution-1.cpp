class MinStack {
public:
    stack<long long> st;
    int minValue;
    MinStack() {}

    void push(int value) {
        if (st.empty()) {
            st.push(value);
            minValue = value;
        } else if (value >= minValue) {
            st.push(value);
        } else {
            st.push((long long)2 * value - minValue);
            minValue = value;
        }
    }

    void pop() {
        if (st.empty())
            return;
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