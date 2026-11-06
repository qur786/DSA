class Solution {
private:
    bool solve(vector<int>& matchsticks, int size, int k, vector<bool>& visited,
               long long target, long long runningSum, int fullfilled,
               int index) {
        if (fullfilled == k - 1)
            return true;
        if (runningSum == target) {
            return solve(matchsticks, size, k, visited, target, 0,
                         fullfilled + 1, 0);
        }

        for (int i = index; i < size; i++) {
            if (visited[i])
                continue;
            if (i > index && matchsticks[i] == matchsticks[i - 1] &&
                !visited[i - 1])
                continue;
            if ((runningSum + matchsticks[i]) > target)
                continue;
            visited[i] = true;
            if (solve(matchsticks, size, k, visited, target,
                      runningSum + matchsticks[i], fullfilled, i + 1))
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
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        long long target = sum / k;

        if (target < matchsticks[0] || sum % k != 0)
            return false;

        vector<bool> visited(size, false);

        return solve(matchsticks, size, k, visited, target, 0, 0, 0);
    }
};