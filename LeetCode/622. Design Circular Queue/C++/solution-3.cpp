class MyCircularQueue {
private:
    int size, capacity, front;
    int* arr;

public:
    MyCircularQueue(int k) {
        this->size = 0;
        this->capacity = k;
        this->front = 0;
        this->arr = new int[k];
    }

    bool enQueue(int value) {
        if (this->isFull())
            return false;
        int index = (this->front + this->size) % this->capacity;
        this->arr[index] = value;
        this->size++;
        return true;
    }

    bool deQueue() {
        if (this->isEmpty())
            return false;
        this->front = (this->front + 1) % this->capacity;
        this->size--;
        return true;
    }

    int Front() {
        if (this->isEmpty())
            return -1;
        int value = this->arr[this->front];

        return value;
    }

    int Rear() {
        if (this->isEmpty())
            return -1;
        int index = (this->front + this->size - 1) % this->capacity;
        int value = this->arr[index];
        return value;
    }

    bool isEmpty() { return this->size == 0; }

    bool isFull() { return this->size == this->capacity; }
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