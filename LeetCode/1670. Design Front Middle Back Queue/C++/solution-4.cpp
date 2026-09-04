class FrontMiddleBackQueue {
private:
    deque<int> left, right;
    bool empty() { return this->left.empty() && this->right.empty(); }
    void balance() {
        if (this->empty())
            return;
        if (left.size() > right.size() + 1) {
            right.push_front(left.back());
            left.pop_back();
        } else if (left.size() < right.size()) {
            left.push_back(right.front());
            right.pop_front();
        }
    }

public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        this->left.push_front(val);
        this->balance();
    }

    void pushMiddle(int val) {
        if (this->left.size() > this->right.size()) {
            this->right.push_front(this->left.back());
            this->left.pop_back();
        }
        this->left.push_back(val);
    }

    void pushBack(int val) {
        this->right.push_back(val);
        this->balance();
    }

    int popFront() {
        if (this->empty())
            return -1;
        int front = this->left.front();
        this->left.pop_front();
        this->balance();
        return front;
    }

    int popMiddle() {
        if (this->empty())
            return -1;
        int middle = this->left.back();
        this->left.pop_back();
        this->balance();
        return middle;
    }

    int popBack() {
        if (this->empty())
            return -1;
        int back;
        if (this->right.empty()) {
            back = this->left.back();
            this->left.pop_back();
        } else {
            back = this->right.back();
            this->right.pop_back();
        }
        this->balance();
        return back;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */