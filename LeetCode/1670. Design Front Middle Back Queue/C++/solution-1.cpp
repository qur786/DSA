class FrontMiddleBackQueue {
private:
    deque<int> left, right;
    bool empty() { return this->left.empty() && this->right.empty(); }
    void balance() {
        if (this->left.size() > this->right.size() + 1) {
            this->right.push_front(this->left.back());
            this->left.pop_back();
        } else if (this->left.size() < this->right.size()) {
            this->left.push_back(this->right.front());
            this->right.pop_front();
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

        int value = this->left.front();
        this->left.pop_front();
        this->balance();
        return value;
    }

    int popMiddle() {
        if (this->empty())
            return -1;
        int value = this->left.back();
        this->left.pop_back();
        this->balance();

        return value;
    }

    int popBack() {
        if (this->empty())
            return -1;
        int value;

        if (this->right.empty()) {
            value = this->left.back();
            this->left.pop_back();
        } else {
            value = this->right.back();
            this->right.pop_back();
        }
        this->balance();

        return value;
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