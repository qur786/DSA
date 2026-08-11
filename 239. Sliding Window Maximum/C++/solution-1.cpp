class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> answer;
        answer.reserve(size - k + 1);
        deque<int> d;

        for (int i = 0; i < size; i++) {
            while (!d.empty() && (i - d.front()) >= k)
                d.pop_front();
            while (!d.empty() && nums[d.back()] <= nums[i])
                d.pop_back();
            d.push_back(i);
            if (i >= (k - 1))
                answer.push_back(nums[d.front()]);
        }

        return answer;
    }
};