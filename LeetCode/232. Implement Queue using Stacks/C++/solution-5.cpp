class MyQueue {
private:
    stack<int> input, output;
    void balance() {
        if (!this->output.empty())
            return;
        while (!this->input.empty()) {
            this->output.push(this->input.top());
            this->input.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) { this->input.push(x); }

    int pop() {
        this->balance();
        int value = this->output.top();
        this->output.pop();
        return value;
    }

    int peek() {
        this->balance();
        int value = this->output.top();
        return value;
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