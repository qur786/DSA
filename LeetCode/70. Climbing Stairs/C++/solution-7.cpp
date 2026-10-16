class Solution {
private:
    int getStairs(int n, vector<int>& fib) {
        if (fib[n] == -1)
            fib[n] = getStairs(n - 1, fib) + getStairs(n - 2, fib);

        return fib[n];
    }

public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        vector<int> fib(n + 1, -1);
        fib[1] = 1;
        fib[2] = 2;

        return getStairs(n, fib);
    }
};