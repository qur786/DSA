class Solution {
private:
    int getFib(int n, vector<int>& f) {
        if (f[n] == -1)
            f[n] = getFib(n - 1, f) + getFib(n - 2, f);

        return f[n];
    }

public:
    int fib(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        vector<int> f(n + 1, -1);
        f[0] = 0;
        f[1] = 1;

        return getFib(n, f);
    }
};