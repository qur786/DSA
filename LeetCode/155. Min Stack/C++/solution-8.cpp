class MinStack {
private:
    stack<long long> st;
    long long minValue = 0;

public:
    MinStack() {}

    void push(int value) {
        long long valueToBe = value;
        if (st.empty()) {
            minValue = value;
        } else if (minValue > value) {
            valueToBe = 2LL * value - minValue;
            minValue = value;
        }
        st.push(valueToBe);
    }

    void pop() {
        long long top = st.top();
        st.pop();
        if (top < minValue) {
            minValue = 2LL * minValue - top;
        }
    }

    int top() {
        long long top = st.top();

        if (top < minValue)
            return minValue;
        return top;
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