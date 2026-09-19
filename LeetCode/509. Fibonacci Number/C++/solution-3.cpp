class Solution {
private:
    int getFib(int n, vector<int>& cache) {
        if (cache[n] != -1)
            return cache[n];

        cache[n] = getFib(n - 1, cache) + getFib(n - 2, cache);

        return cache[n];
    }

public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        vector<int> cache(n + 1, -1);
        cache[0] = 0;
        cache[1] = 1;

        return getFib(n, cache);
    }
};