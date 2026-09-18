class Solution {
private:
    int getMinCost(vector<int>& cost, vector<int>& minCosts, int step) {
        if (minCosts[step] != INT_MAX)
            return minCosts[step];

        minCosts[step] = cost[step] + min(getMinCost(cost, minCosts, step - 1),
                                          getMinCost(cost, minCosts, step - 2));

        return minCosts[step];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> minCosts(size + 1, INT_MAX);
        minCosts[0] = cost[0];
        minCosts[1] = cost[1];

        return min(getMinCost(cost, minCosts, size - 1),
                   getMinCost(cost, minCosts, size - 2));
    }
};