class Solution {
private:
    bool canMak(vector<int>& matchsticks, vector<bool>& visited, int fullfilled,
                long long runningSum, long long target, int size, int k,
                int index) {
        if (fullfilled == k - 1)
            return true;
        if (runningSum == target)
            return canMak(matchsticks, visited, fullfilled + 1, 0, target, size,
                          k, 0);

        for (int i = index; i < size; i++) {
            if (visited[i])
                continue;
            if (i > index && matchsticks[i] == matchsticks[i - 1] &&
                !visited[i - 1])
                continue;
            if (runningSum + matchsticks[i] > target)
                continue;
            visited[i] = true;
            if (canMak(matchsticks, visited, fullfilled,
                       runningSum + matchsticks[i], target, size, k, i + 1))
                return true;

            visited[i] = false;
        }
        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        int k = 4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        int size = matchsticks.size();
        long long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
        long long target = sum / k;

        if (matchsticks[0] > target || sum % k != 0)
            return false;
        vector<bool> visited(size, false);

        return canMak(matchsticks, visited, 0, 0, target, size, k, 0);
    }
};