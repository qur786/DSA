class MyStack {
public:
    queue<int> input;
    MyStack() {}

    void push(int x) {
        this->input.push(x);
        for (int i = 1; i < this->input.size(); i++) {
            this->input.push(this->input.front());
            this->input.pop();
        }
    }

    int pop() {
        int top = this->input.front();
        this->input.pop();

        return top;
    }

    int top() {
        int top = this->input.front();

        return top;
    }

    bool empty() { return this->input.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */