class Solution {
public:
    int getMaxLenPalindrome(const string& s, int left, int right) {
        int size = s.size();
        while (left >= 0 && right < size) {
            if (s[left] != s[right])
                break;
            left--;
            right++;
        }

        return right - left - 1;
    }
    string longestPalindrome(string s) {
        int size = s.size(), maxLen = INT_MIN, maxIndex = -1;

        for (int i = 0; i < size; i++) {
            int m = max(getMaxLenPalindrome(s, i, i),
                        getMaxLenPalindrome(s, i, i + 1));
            if (m > maxLen) {
                maxLen = m;
                maxIndex = i - ((maxLen - 1) / 2);
            }
        }

        return s.substr(maxIndex, maxLen);
    }
};