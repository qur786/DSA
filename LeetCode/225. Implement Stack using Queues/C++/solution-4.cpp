class MyStack {
private:
    queue<int> input, store;
    void transfer() {
        while (!store.empty()) {
            input.push(store.front());
            store.pop();
        }
    }

public:
    MyStack() {}

    void push(int x) {
        this->input.push(x);
        this->transfer();
        swap(this->input, this->store);
    }

    int pop() {
        int top = this->store.front();
        this->store.pop();
        return top;
    }

    int top() {
        int top = this->store.front();
        return top;
    }

    bool empty() { return this->store.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */