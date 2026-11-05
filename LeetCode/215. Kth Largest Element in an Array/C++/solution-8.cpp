class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        std::ranges::for_each(nums, [&](int data) {
            pq.push(data);
            if (pq.size() > k)
                pq.pop();
        });

        return pq.top();
    }
};