class Solution {
private:
    int climb(int n, vector<int>& stairs) {
        if (stairs[n] == -1)
            stairs[n] = climb(n - 1, stairs) + climb(n - 2, stairs);

        return stairs[n];
    }

public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        vector<int> stairs(n + 1, -1);
        stairs[1] = 1;
        stairs[2] = 2;

        return climb(n, stairs);
    }
};