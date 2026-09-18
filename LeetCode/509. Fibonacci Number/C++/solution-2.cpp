class Solution {
private:
    vector<int> fb;
    int getFib(int n) {
        if (fb[n] != -1)
            return fb[n];

        return getFib(n - 1) + getFib(n - 2);
    }

public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        fb.assign(n + 1, -1);
        fb[0] = 0;
        fb[1] = 1;

        return getFib(n);
    }
};