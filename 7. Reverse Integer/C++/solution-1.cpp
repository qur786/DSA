class Solution {
public:
    int reverse(int x) {
        bool isNeg = false;
        long long num = x;
        if (num < 0) {
            isNeg = true;
            num = -num;
        }
        long long rev = 0;
        while (num) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        if (rev >= INT_MAX || rev <= INT_MIN)
            return 0;

        return isNeg ? -rev : rev;
    }
};