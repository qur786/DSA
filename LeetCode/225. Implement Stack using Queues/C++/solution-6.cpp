class MyStack {
private:
    queue<int> input, temp;
    void balance() {
        while (!this->input.empty()) {
            this->temp.push(this->input.front());
            this->input.pop();
        }
    }

public:
    MyStack() {}

    void push(int x) {
        this->temp.push(x);
        this->balance();
        swap(this->temp, this->input);
    }

    int pop() {
        int front = this->input.front();
        this->input.pop();
        return front;
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