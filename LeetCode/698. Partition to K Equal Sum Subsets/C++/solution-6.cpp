class Solution {
private:
    bool solve(vector<int>& nums, int k, vector<bool>& visited, int size,
               long long target, long long runningSum, int fullfilled,
               int index) {
        if (fullfilled == k - 1)
            return true;

        if (runningSum == target) {
            return solve(nums, k, visited, size, target, 0, fullfilled + 1, 0);
        }

        for (int i = index; i < size; i++) {
            if (visited[i])
                continue;
            if (i > index && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;
            if ((runningSum + nums[i]) > target)
                continue;
            visited[i] = true;
            if (solve(nums, k, visited, size, target, runningSum + nums[i],
                      fullfilled, i + 1))
                return true;
            visited[i] = false;
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int size = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        if (sum % k != 0)
            return false;
        long long target = sum / k;
        sort(nums.begin(), nums.end(), greater<int>());
        if (nums[0] > target)
            return false;
        vector<bool> visited(size, false);

        return solve(nums, k, visited, size, target, 0, 0, 0);
    }
};