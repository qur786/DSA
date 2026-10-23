class Solution {
private:
    bool solve(vector<int>& matchsticks, int k, long long sumSoFar,
               long long target, int size, int index, vector<bool>& visited,
               int fullfilled) {
        if (fullfilled == k - 1)
            return true;

        if (target == sumSoFar) {
            return solve(matchsticks, k, 0, target, size, 0, visited,
                         fullfilled + 1);
        }

        for (int i = index; i < size; i++) {
            if (visited[i])
                continue;
            if (matchsticks[i] + sumSoFar > target)
                continue;
            if (i > index && matchsticks[i] == matchsticks[i - 1] &&
                !visited[i - 1])
                continue;
            visited[i] = true;
            if (solve(matchsticks, k, sumSoFar + matchsticks[i], target, size,
                      i + 1, visited, fullfilled))
                return true;
            visited[i] = false;
        }

        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        int size = matchsticks.size();
        long long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
        int k = 4;
        long long target = sum / 4;

        if (target < matchsticks[0])
            return false;
        if (sum % k != 0)
            return false;

        vector<bool> visited(size, false);

        return solve(matchsticks, k, 0, target, size, 0, visited, 0);
    }
};