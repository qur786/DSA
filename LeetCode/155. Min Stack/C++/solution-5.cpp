class MinStack {
private:
    long long minValue = 0;
    stack<long long> st;

public:
    MinStack() {}

    void push(int value) {
        long long valueToBe = value;
        if (st.empty()) {
            minValue = value;
        } else if (minValue > value) {
            valueToBe = (long long)2 * value - minValue;
            minValue = value;
        }

        st.push(valueToBe);
    }

    void pop() {
        if (st.top() < minValue) {
            minValue = (long long)2 * minValue - st.top();
        }
        st.pop();
    }

    int top() {
        long long top = st.top();
        return top < minValue ? minValue : top;
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