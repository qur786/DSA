class Solution {
private:
    bool canPart(vector<int>& nums, vector<bool>& visited, long long runningSum,
                 long long target, int size, int k, int fullfilled, int index) {
        if (fullfilled == k - 1)
            return true;
        if (runningSum == target) {
            return canPart(nums, visited, 0, target, size, k, fullfilled + 1,
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
            if (canPart(nums, visited, runningSum + nums[i], target, size, k,
                        fullfilled, i + 1))
                return true;
            visited[i] = false;
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long target = sum / k;
        int size = nums.size();

        if (sum % k != 0)
            return false;
        if (nums[0] > target)
            return false;
        vector<bool> visited(size, false);

        return canPart(nums, visited, 0, target, size, k, 0, 0);
    }
};