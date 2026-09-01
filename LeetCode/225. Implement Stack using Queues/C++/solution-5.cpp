class MyStack {
private:
    queue<int> input, store;

public:
    MyStack() {}

    void push(int x) {
        input.push(x);
        while (!store.empty()) {
            input.push(store.front());
            store.pop();
        }
        swap(input, store);
    }

    int pop() {
        if (this->empty())
            return -1;
        int front = this->store.front();
        this->store.pop();

        return front;
    }

    int top() {
        if (this->empty())
            return -1;
        int front = this->store.front();

        return front;
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