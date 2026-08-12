class MyCircularDeque {
private:
    int* arr = nullptr;
    int size, front, capacity;

public:
    MyCircularDeque(int k) {
        this->size = 0;
        this->front = 0;
        this->capacity = k;
        this->arr = new int[k];
    }

    bool insertFront(int value) {
        if (this->isFull())
            return false;
        this->front = (this->front - 1 + this->capacity) % this->capacity;
        this->arr[this->front] = value;
        this->size++;
        return true;
    }

    bool insertLast(int value) {
        if (this->isFull())
            return false;
        int index = (this->front + this->size) % this->capacity;
        this->arr[index] = value;
        this->size++;
        return true;
    }

    bool deleteFront() {
        if (this->isEmpty())
            return false;
        this->front = (this->front + 1) % this->capacity;
        this->size--;

        return true;
    }

    bool deleteLast() {
        if (this->isEmpty())
            return false;
        this->size--;

        return true;
    }

    int getFront() {
        if (this->isEmpty())
            return -1;
        return this->arr[this->front];
    }

    int getRear() {
        if (this->isEmpty())
            return -1;
        int index = (this->front + this->size - 1) % this->capacity;
        return this->arr[index];
    }

    bool isEmpty() { return this->size == 0; }

    bool isFull() { return this->size == this->capacity; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */