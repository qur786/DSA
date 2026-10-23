class Solution {
private:
    bool canPart(vector<int>& nums, int k, long long sumSoFar, long long target,
                 int fullfilled, int index, int size, vector<bool>& visited) {

        if (fullfilled == k - 1)
            return true;

        if (sumSoFar == target) {
            return canPart(nums, k, 0, target, fullfilled + 1, 0, size,
                           visited);
        }

        for (int i = index; i < size; i++) {
            if (visited[i])
                continue;
            if (i > index && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;
            if (sumSoFar + nums[i] > target)
                continue;
            visited[i] = true;
            if (canPart(nums, k, sumSoFar + nums[i], target, fullfilled, i + 1,
                        size, visited))
                return true;
            visited[i] = false;
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int size = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        sort(nums.begin(), nums.end(), greater<int>());
        long long target = sum / k;

        if (nums[0] > target)
            return false;
        if (sum % k != 0)
            return false;

        vector<bool> visited(size, false);

        return canPart(nums, k, 0, target, 0, 0, size, visited);
    }
};