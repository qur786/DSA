class Solution {
private:
    int solve(int n, vector<int>& cost, vector<int>& minCosts) {
        if (minCosts[n] == -1)
            minCosts[n] = cost[n] + min(solve(n - 1, cost, minCosts),
                                        solve(n - 2, cost, minCosts));

        return minCosts[n];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> minCosts(size, -1);
        minCosts[0] = cost[0];
        minCosts[1] = cost[1];

        return min(solve(size - 1, cost, minCosts),
                   solve(size - 2, cost, minCosts));
    }
};