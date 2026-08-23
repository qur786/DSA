class MinStack {
private:
    stack<int> st, minSt;

public:
    MinStack() {}

    void push(int value) {
        st.push(value);
        if (minSt.empty() || minSt.top() > value)
            minSt.push(value);
        else
            minSt.push(minSt.top());
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() {
        int top = st.top();
        return top;
    }

    int getMin() {
        int min = minSt.top();

        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */