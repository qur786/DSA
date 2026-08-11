class MyQueue {
private:
    stack<int> input, output;
    void transferFromInptToOutput() {
        if (!this->output.empty())
            return;
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) { this->input.push(x); }

    int pop() {
        this->transferFromInptToOutput();
        int front = this->output.top();
        this->output.pop();
        return front;
    }

    int peek() {
        this->transferFromInptToOutput();
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