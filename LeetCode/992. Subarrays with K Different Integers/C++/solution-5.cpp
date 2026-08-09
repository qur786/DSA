class Solution {
private:
    int subarraysWithAtMostK(vector<int>& nums, int k) {
        int left = 0, size = nums.size();
        int count = 0;
        unordered_map<int, int> numCount;

        for (int right = 0; right < size; right++) {
            numCount[nums[right]]++;
            while (numCount.size() > k) {
                numCount[nums[left]]--;
                if (numCount[nums[left]] == 0)
                    numCount.erase(nums[left]);
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return this->subarraysWithAtMostK(nums, k) -
               this->subarraysWithAtMostK(nums, k - 1);
    }
};