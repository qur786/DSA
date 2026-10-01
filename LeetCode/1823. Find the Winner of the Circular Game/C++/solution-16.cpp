class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 0)
            return 1;

        return (findTheWinner(n - 1, k) - 1 + k) % n + 1;
    }
};