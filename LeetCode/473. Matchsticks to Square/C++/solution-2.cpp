class Solution {
private:
    bool makeSq(vector<int>& matchsticks, vector<bool>& visited,
                long long target, long long runningSum, int fullfilled, int k,
                int size, int index) {
        if (fullfilled == k - 1)
            return true;
        if (runningSum == target) {
            return makeSq(matchsticks, visited, target, 0, fullfilled + 1, k,
                          size, 0);
        }

        for (int i = index; i < size; i++) {
            if (visited[i])
                continue;
            if (runningSum + matchsticks[i] > target)
                continue;
            if (i > index && matchsticks[i] == matchsticks[i - 1] &&
                !visited[i - 1])
                continue;
            visited[i] = true;
            if (makeSq(matchsticks, visited, target,
                       runningSum + matchsticks[i], fullfilled, k, size, i + 1))
                return true;
            visited[i] = false;
        }

        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        int k = 4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        long long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
        long long target = sum / k;
        int size = matchsticks.size();
        vector<bool> visited(size, false);

        if (sum % k != 0)
            return false;
        if (matchsticks[0] > target)
            return false;

        return makeSq(matchsticks, visited, target, 0, 0, k, size, 0);
    }
};