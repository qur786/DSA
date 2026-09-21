class Solution {
private:
    int calClimb(int n, vector<int>& climb) {
        if (climb[n] == -1)
            climb[n] = calClimb(n - 1, climb) + calClimb(n - 2, climb);

        return climb[n];
    }

public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        vector<int> climb(n + 1, -1);
        climb[1] = 1;
        climb[2] = 2;

        return calClimb(n, climb);
    }
};