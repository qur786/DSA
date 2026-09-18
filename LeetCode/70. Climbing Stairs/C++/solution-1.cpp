class Solution {
private:
    int uniqSteps(int n, int steps, int& count) {
        if (n == steps) {
            count += 1;
            return count;
        }

        if (steps + 1 <= n) {
            uniqSteps(n, steps + 1, count);
        }
        if (steps + 2 <= n) {
            uniqSteps(n, steps + 2, count);
        }

        return count;
    }

public:
    int climbStairs(int n) {
        int count = 0;
        return uniqSteps(n, 0, count);
    }
};