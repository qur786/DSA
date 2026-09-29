class MyQueue {
private:
    stack<int> store, input;

public:
    MyQueue() {}

    void push(int x) {
        while (!store.empty()) {
            input.push(store.top());
            store.pop();
        }
        input.push(x);
        while (!input.empty()) {
            store.push(input.top());
            input.pop();
        }
    }

    int pop() {
        int value = store.top();
        store.pop();

        return value;
    }

    int peek() {
        int value = store.top();

        return value;
    }

    bool empty() { return store.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */