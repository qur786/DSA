class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> monotonicDecreasingDeque;
        int size = nums.size();
        int slidingWindowAnswerSize = size - k + 1;
        vector<int> slidingWindowAnswer;
        slidingWindowAnswer.reserve(slidingWindowAnswerSize);

        for (int i = 0; i < size; i++) {
            while (!monotonicDecreasingDeque.empty() &&
                   nums[monotonicDecreasingDeque.back()] <= nums[i])
                monotonicDecreasingDeque.pop_back();
            while (!monotonicDecreasingDeque.empty() &&
                   (i - monotonicDecreasingDeque.front()) >= k)
                monotonicDecreasingDeque.pop_front();

            monotonicDecreasingDeque.push_back(i);

            if (i >= (k - 1))
                slidingWindowAnswer.push_back(
                    nums[monotonicDecreasingDeque.front()]);
        }

        return slidingWindowAnswer;
    }
};