class Solution {
private:
    int getFib(int n, vector<int>& fb) {
        if (fb[n] == -1)
            fb[n] = getFib(n - 1, fb) + getFib(n - 2, fb);

        return fb[n];
    }

public:
    int fib(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        vector<int> fb(n + 1, -1);
        fb[0] = 0;
        fb[1] = 1;

        return getFib(n, fb);
    }
};