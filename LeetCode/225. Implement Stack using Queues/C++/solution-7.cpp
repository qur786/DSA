class MyStack {
    queue<int> store, input;

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
        int value = store.front();
        store.pop();
        return value;
    }

    int top() {
        int value = store.front();
        return value;
    }

    bool empty() { return store.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */