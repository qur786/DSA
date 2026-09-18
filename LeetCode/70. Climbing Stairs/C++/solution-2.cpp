class Solution {
private:
    vector<int> steps = vector<int>(46, -1);

public:
    int climbStairs(int n) {
        steps[0] = 0;
        steps[1] = 1;
        steps[2] = 2;

        if (steps[n] != -1)
            return steps[n];

        steps[n] = climbStairs(n - 1) + climbStairs(n - 2);

        return steps[n];
    }
};