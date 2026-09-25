class Solution {
private:
    bool canMakSq(vector<int>& matchsticks, vector<bool>& visited,
                  int fullfilled, long long runningSum, long long target,
                  int size, int index, int k) {
        if (fullfilled == k - 1)
            return true;

        if (runningSum == target) {
            return canMakSq(matchsticks, visited, fullfilled + 1, 0, target,
                            size, 0, k);
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
            if (canMakSq(matchsticks, visited, fullfilled,
                         runningSum + matchsticks[i], target, size, i + 1, k))
                return true;

            visited[i] = false;
        }

        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        int k = 4;
        long long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
        long long target = sum / k;
        int size = matchsticks.size();

        if (sum % k != 0 || matchsticks[0] > target)
            return false;

        vector<bool> visited(size, false);

        return canMakSq(matchsticks, visited, 0, 0, target, size, 0, k);
    }
};