class Solution {
public:
    double myPow(double x, int n) {
        if (n == 1)
            return x;
        if (n == 0)
            return 1;
        if (n == INT_MIN)
            return 1 / x * myPow(x, n + 1);
        if (n < 0)
            return myPow(1 / x, -n);
        double half = myPow(x, n / 2);
        return n % 2 == 0 ? half * half : half * half * x;
    }
};