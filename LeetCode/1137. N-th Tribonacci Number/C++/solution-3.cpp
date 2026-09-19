class Solution {
private:
    int getTri(int n, vector<int>& cache) {
        if (cache[n] != -1)
            return cache[n];

        cache[n] =
            getTri(n - 1, cache) + getTri(n - 2, cache) + getTri(n - 3, cache);

        return cache[n];
    }

public:
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;
        vector<int> cache(n + 1, -1);
        cache[0] = 0;
        cache[1] = 1;
        cache[2] = 1;
        return getTri(n, cache);
    }
};