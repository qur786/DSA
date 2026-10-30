class Solution {
private:
    int solve(int n, vector<int>& tri) {
        if (tri[n] == -1)
            tri[n] = solve(n - 1, tri) + solve(n - 2, tri) + solve(n - 3, tri);

        return tri[n];
    }

public:
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;

        vector<int> tri(n + 1, -1);
        tri[0] = 0;
        tri[1] = 1;
        tri[2] = 1;

        return solve(n, tri);
    }
};