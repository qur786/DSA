class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int left = 0;
        string numString = to_string(num);
        int size = numString.size();
        int kBeauty = 0;

        for (int right = k - 1; right < size; right++) {
            if ((right - left + 1) > k)
                left++;

            if (right - left + 1 == k) {
                int n = stoi(numString.substr(left, k));
                if (n != 0 && num % n == 0)
                    kBeauty++;
            }
        }

        return kBeauty;
    }
};