class MyStack {
public:
    queue<int> store, input;
    MyStack() {}

    void push(int x) {
        this->input.push(x);
        while (!this->store.empty()) {
            this->input.push(this->store.front());
            this->store.pop();
        }
        swap(this->store, this->input);
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