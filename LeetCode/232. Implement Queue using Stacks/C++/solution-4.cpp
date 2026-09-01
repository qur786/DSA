class MyQueue {
private:
    stack<int> input, output;
    void balance() {
        if (!output.empty())
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
        if (this->empty())
            return -1;
        this->balance();
        int top = this->output.top();
        this->output.pop();
        return top;
    }

    int peek() {
        if (this->empty())
            return -1;
        this->balance();
        int top = this->output.top();
        return top;
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