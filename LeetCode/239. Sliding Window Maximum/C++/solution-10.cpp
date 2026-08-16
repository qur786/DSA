class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int size = nums.size();
        vector<int> maxValues;
        maxValues.reserve(size - k + 1);

        for (int i = 0; i < size; i++) {
            while (!dq.empty() && (i - dq.front()) >= k)
                dq.pop_front();
            while (!dq.empty() && (nums[i] >= nums[dq.back()]))
                dq.pop_back();
            dq.push_back(i);

            if (i >= (k - 1))
                maxValues.push_back(nums[dq.front()]);
        }

        return maxValues;
    }
};