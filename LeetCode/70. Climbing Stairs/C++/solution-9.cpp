class Solution {
private:
    int solve(int n, vector<int>& steps) {
        if (steps[n] == -1)
            steps[n] = solve(n - 1, steps) + solve(n - 2, steps);

        return steps[n];
    }

public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        vector<int> steps(n + 1, -1);
        steps[1] = 1;
        steps[2] = 2;

        return solve(n, steps);
    }
};