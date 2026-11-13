class Solution {
private:
    int f(int n, vector<int>& fib) {
        if (fib[n] == -1)
            fib[n] = f(n - 1, fib) + f(n - 2, fib);

        return fib[n];
    }

public:
    int fib(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        vector<int> fib(n + 1, -1);
        fib[0] = 0;
        fib[1] = 1;

        return f(n, fib);
    }
};