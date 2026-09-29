class Solution {
private:
    bool canMakeSq(vector<int>& nums, vector<bool>& visited,
                   long long runningSum, long long target, int fullfilled,
                   int size, int k, int index) {
        if (fullfilled == k - 1)
            return true;
        if (runningSum == target) {
            return canMakeSq(nums, visited, 0, target, fullfilled + 1, size, k,
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
            if (canMakeSq(nums, visited, runningSum + nums[i], target,
                          fullfilled, size, k, i + 1))
                return true;
            visited[i] = false;
        }

        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        int k = 4;
        int size = matchsticks.size();
        long long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
        long long target = sum / k;

        if (sum % k != 0)
            return false;
        if (matchsticks[0] > target)
            return false;

        vector<bool> visited(size, false);

        return canMakeSq(matchsticks, visited, 0, target, 0, size, k, 0);
    }
};