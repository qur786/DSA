class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> totalCosts(n + 1, INT_MAX);
        totalCosts[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                int prev = i - j;
                if (prev < 0 || totalCosts[prev] == INT_MAX)
                    continue;

                int cost = costs[i - 1];

                totalCosts[i] =
                    min(totalCosts[i], totalCosts[prev] + cost + j * j);
            }
        }
        return totalCosts[n];
    }
};