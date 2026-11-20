class Solution {
private:
    bool solve(vector<int>& nums, vector<bool>& visited, long long runningSum,
               long long target, int size, int k, int index, int fullfilled) {
        if (fullfilled == k - 1)
            return true;
        if (fullfilled == k)
            return false;
        if (runningSum == target)
            return solve(nums, visited, 0, target, size, k, 0, fullfilled + 1);

        for (int i = index; i < size; i++) {
            if (visited[i])
                continue;
            if (nums[i] + runningSum > target)
                continue;
            visited[i] = true;
            if (solve(nums, visited, runningSum + nums[i], target, size, k,
                      i + 1, fullfilled))
                return true;
            visited[i] = false;
        }

        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        int size = matchsticks.size();
        int k = 4;
        long long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        long long target = sum / k;
        if (sum % k != 0 || matchsticks[0] > target)
            return false;
        vector<bool> visited(size, false);

        return solve(matchsticks, visited, 0, target, size, k, 0, 0);
    }
};