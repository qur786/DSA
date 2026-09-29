class Solution {
private:
    bool canPart(vector<int>& nums, vector<bool>& visited, long long target,
                 int fullfilled, int size, int k, long long runningSum,
                 int index) {
        if (fullfilled == k - 1)
            return true;
        if (runningSum == target) {
            return canPart(nums, visited, target, fullfilled + 1, size, k, 0,
                           0);
        }

        for (int i = index; i < size; i++) {
            if (visited[i])
                continue;
            if (i > index && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;
            if (runningSum + nums[i] > target)
                continue;

            visited[i] = true;
            if (canPart(nums, visited, target, fullfilled, size, k,
                        runningSum + nums[i], i + 1))
                return true;
            visited[i] = false;
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        int size = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long target = sum / k;
        if (sum % k != 0)
            return false;
        if (target < nums[0])
            return false;
        vector<bool> visited(size, false);
        return canPart(nums, visited, target, 0, size, k, 0, 0);
    }
};