class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        deque<int> dq;
        vector<int> answer;
        answer.reserve(size - k + 1);

        for (int i = 0; i < size; i++) {
            while (!dq.empty() && (i - dq.front()) >= k)
                dq.pop_front();
            while (!dq.empty() && (nums[i] >= nums[dq.back()]))
                dq.pop_back();
            dq.push_back(i);

            if (i >= (k - 1))
                answer.push_back(nums[dq.front()]);
        }

        return answer;
    }
};