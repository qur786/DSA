class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> values;
    int limit = 0;
    void push(int val) {
        values.push(val);
        if (values.size() > limit)
            values.pop();
    }

public:
    KthLargest(int k, vector<int>& nums) {
        limit = k;
        std::ranges::for_each(nums, [&](int data) { this->push(data); });
    }

    int add(int val) {
        this->push(val);

        return values.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */