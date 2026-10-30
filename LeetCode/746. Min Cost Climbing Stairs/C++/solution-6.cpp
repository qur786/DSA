class Solution {
private:
    int solve(int n, vector<int>& cost, vector<int>& minCosts) {
        if (minCosts[n] == INT_MAX)
            minCosts[n] = min(solve(n - 1, cost, minCosts),
                              solve(n - 2, cost, minCosts)) +
                          cost[n];

        return minCosts[n];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> minCosts(size, INT_MAX);
        minCosts[0] = cost[0];
        minCosts[1] = cost[1];

        return min(solve(size - 1, cost, minCosts),
                   solve(size - 2, cost, minCosts));
    }
};