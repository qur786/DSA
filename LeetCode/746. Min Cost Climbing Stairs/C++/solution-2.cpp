class Solution {
private:
    int getMinCost(int n, vector<int>& cache, vector<int>& cost) {
        if (cache[n] != INT_MAX)
            return cache[n];

        cache[n] = min(getMinCost(n - 1, cache, cost),
                       getMinCost(n - 2, cache, cost)) +
                   cost[n];

        return cache[n];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> cache(size, INT_MAX);
        cache[0] = cost[0];
        cache[1] = cost[1];
        return min(getMinCost(size - 1, cache, cost),
                   getMinCost(size - 2, cache, cost));
    }
};