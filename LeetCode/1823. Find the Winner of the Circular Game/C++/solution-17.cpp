class Solution {
private:
    int findWinner(int n, int k) {
        if (n == 0)
            return 1;

        return (findWinner(n - 1, k) + k) % n;
    }

public:
    int findTheWinner(int n, int k) { return findWinner(n, k) + 1; }
};