class Solution {
private:
    bool canPart(vector<int> & nums, vector<bool> & visited, int fullfilled, long long target, long long runningSum, int size, int k, int index) {
        if (fullfilled == k - 1) return true;
        if (runningSum == target) {
            return canPart(nums, visited, fullfilled + 1, target, 0, size, k, 0);
        }

        for (int i = index; i < size; i++) {
            if (visited[i]) continue;
            if (i > index && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            if (runningSum + nums[i] > target) continue;
            visited[i] = true;
            if (
            canPart(nums, visited, fullfilled, target, runningSum + nums[i], size, k, i + 1)) return true;
            visited[i] = false;
        }

        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long target = sum / k;

        if (nums[0] > target || sum % k != 0) return false;
        int size = nums.size();
        vector<bool> visited(size, false);
        return canPart(nums, visited, 0, target, 0, size, k, 0);
    }
};