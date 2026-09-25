class Solution {
private:
    bool canPart(vector<int>& nums, vector<bool>& visited, int fullfilled,
                 int k, long long runningSum, long long target, int size,
                 int index) {
        if (fullfilled == k - 1)
            return true;

        if (runningSum == target) {
            return canPart(nums, visited, fullfilled + 1, k, 0, target, size,
                           0);
        }

        for (int i = index; i < size; i++) {
            if (visited[i])
                continue;
            if (runningSum + nums[i] > target)
                continue;
            if (i > index && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;

            visited[i] = true;
            if (canPart(nums, visited, fullfilled, k, runningSum + nums[i],
                        target, size, i + 1))
                return true;
            visited[i] = false;
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        if (sum % k != 0)
            return false;
        long long target = sum / k;
        if (nums[0] > target)
            return false;
        int size = nums.size();
        vector<bool> visited(size, false);

        return canPart(nums, visited, 0, k, 0, target, size, 0);
    }
};