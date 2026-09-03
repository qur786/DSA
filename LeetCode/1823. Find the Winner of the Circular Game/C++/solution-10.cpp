class Solution {
private:
    int findTheWin(int n, int k) {
        if (n == 1)
            return 0;

        return (findTheWin(n - 1, k) + k) % n;
    }

public:
    int findTheWinner(int n, int k) { return findTheWin(n, k) + 1; }
};