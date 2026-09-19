class Solution {
private:
    int climbSt(int n, vector<int>& cache) {
        if (cache[n] != -1)
            return cache[n];

        cache[n] = climbSt(n - 1, cache) + climbSt(n - 2, cache);

        return cache[n];
    }

public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        vector<int> cache(n + 1, -1);

        cache[1] = 1;
        cache[2] = 2;

        return climbSt(n, cache);
    }
};