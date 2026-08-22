class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum = 0, pro = 1;
        int x = n;
        while (x) {
            int d = x % 10;
            x /= 10;
            sum += d;
            pro *= d;
        }

        long long value = sum + pro;

        return (n % value) == 0;
    }
};