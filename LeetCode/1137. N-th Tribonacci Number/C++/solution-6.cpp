class Solution {
private:
    int getTri(int n, vector<int>& fb) {
        if (fb[n] == -1)
            fb[n] = getTri(n - 1, fb) + getTri(n - 2, fb) + getTri(n - 3, fb);

        return fb[n];
    }

public:
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;

        vector<int> fb(n + 1, -1);

        fb[0] = 0;
        fb[1] = 1;
        fb[2] = 1;

        return getTri(n, fb);
    }
};