class Solution {
private:
    int minCost(int n, vector<int>& cost, vector<int>& minCosts) {
        if (minCosts[n] == INT_MAX)
            minCosts[n] = cost[n] + min(minCost(n - 1, cost, minCosts),
                                        minCost(n - 2, cost, minCosts));

        return minCosts[n];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 1)
            return cost[0];
        if (cost.size() == 2)
            return min(cost[0], cost[1]);
        int n = cost.size();
        vector<int> minCosts(n, INT_MAX);
        minCosts[0] = cost[0];
        minCosts[1] = cost[1];

        return min(minCost(n - 1, cost, minCosts),
                   minCost(n - 2, cost, minCosts));
    }
};