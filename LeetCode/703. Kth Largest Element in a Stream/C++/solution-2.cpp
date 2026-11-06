class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int limit;
    void push(int n) {
        pq.push(n);
        if (pq.size() > limit)
            pq.pop();
    }

public:
    KthLargest(int k, vector<int>& nums) {
        this->limit = k;
        for (int n : nums) {
            this->push(n);
        }
    }

    int add(int val) {
        this->push(val);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */