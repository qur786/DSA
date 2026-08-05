class MyQueue {
private:
    void transferFromInputToOutput() {
        if (!this->output.empty())
            return;
        while (!this->input.empty()) {
            this->output.push(this->input.top());
            this->input.pop();
        }
    }

public:
    stack<int> input, output;
    MyQueue() {}

    void push(int x) { input.push(x); }

    int pop() {
        this->transferFromInputToOutput();
        int front = this->output.top();
        this->output.pop();

        return front;
    }

    int peek() {
        this->transferFromInputToOutput();
        int front = this->output.top();

        return front;
    }

    bool empty() { return this->input.empty() && this->output.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */