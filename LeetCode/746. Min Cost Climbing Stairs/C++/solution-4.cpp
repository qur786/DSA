class Solution {
private:
    int getMinCost(int n, vector<int>& cost, vector<int>& minCosts) {
        if (minCosts[n] == INT_MAX)
            minCosts[n] =
                cost[n] + min(getMinCost(n - 1, cost, minCosts),
                                 getMinCost(n - 2, cost, minCosts));

        return minCosts[n];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        if (n == 1)
            return cost[0];
        if (n == 2)
            return min(cost[0], cost[1]);
        vector<int> minCosts(n, INT_MAX);
        minCosts[0] = cost[0];
        minCosts[1] = cost[1];

        return min(getMinCost(n - 1, cost, minCosts),
                   getMinCost(n - 2, cost, minCosts));
    }
};