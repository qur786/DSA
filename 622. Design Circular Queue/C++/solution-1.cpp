class MyCircularQueue {
private:
    int size, capacity, front;
    vector<int> arr;

public:
    MyCircularQueue(int k) {
        this->size = 0;
        this->capacity = k;
        this->front = 0;
        this->arr.resize(k);
    }

    bool enQueue(int value) {
        if (this->isFull())
            return false;
        int index = (this->front + this->size) % this->capacity;
        this->size++;
        this->arr[index] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;
        this->front = (this->front + 1) % this->capacity;
        this->size--;
        return true;
    }

    int Front() {
        if (this->isEmpty())
            return -1;
        return this->arr[this->front];
    }

    int Rear() {
        if (this->isEmpty())
            return -1;
        return this->arr[(this->front + this->size - 1) % this->capacity];
    }

    bool isEmpty() { return this->size == 0; }

    bool isFull() { return this->capacity == this->size; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */