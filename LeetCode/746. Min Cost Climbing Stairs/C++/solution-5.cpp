class Solution {
private:
    int getMinCost(vector<int>& cost, vector<int>& minCosts, int n) {
        if (minCosts[n] == -1)
            minCosts[n] = cost[n] + min(getMinCost(cost, minCosts, n - 1),
                                        getMinCost(cost, minCosts, n - 2));

        return minCosts[n];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> minCosts(cost.size(), -1);
        minCosts[0] = cost[0];
        minCosts[1] = cost[1];
        return min(getMinCost(cost, minCosts, n - 1),
                   getMinCost(cost, minCosts, n - 2));
    }
};