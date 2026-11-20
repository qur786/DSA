class Solution {
private:
    bool solve(vector<int>& nums, vector<bool>& visited, long long runningSum,
               long long target, int k, int size, int index, int fullfilled) {
        if (fullfilled == k - 1)
            return true;
        if (runningSum == target) {
            return solve(nums, visited, 0, target, k, size, 0, fullfilled + 1);
        }

        for (int i = index; i < size; i++) {
            if (visited[i])
                continue;
            if (runningSum + nums[i] > target)
                continue;
            visited[i] = true;
            if (solve(nums, visited, runningSum + nums[i], target, k, size,
                      i + 1, fullfilled))
                return true;
            visited[i] = false;
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int size = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long target = sum / k;
        vector<bool> visited(size, false);

        if (sum % k != 0 || nums[0] > target)
            return false;

        return solve(nums, visited, 0, target, k, size, 0, 0);
    }
};