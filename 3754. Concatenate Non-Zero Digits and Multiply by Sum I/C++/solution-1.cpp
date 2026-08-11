class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0, x = 0;
        int p = 0;

        while (n > 0) {
            int rem = n % 10;
            sum += rem;
            x = rem > 0 ? (x + rem * pow(10, p++)) : x;
            n /= 10;
        }

        return sum * x;
    }
};