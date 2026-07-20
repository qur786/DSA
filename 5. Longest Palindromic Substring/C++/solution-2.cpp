class Solution {
public:
    int getPalindromeLen(const string& s, int left, int right) {
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
        int maxLen = 0, size = s.size(), maxIndex = -1;

        for (int i = 0; i < size; i++) {
            int m =
                max(getPalindromeLen(s, i, i), getPalindromeLen(s, i, i + 1));
            if (m > maxLen) {
                maxLen = m;
                maxIndex = i - (maxLen + 1) / 2 + 1;
            }
        }

        return s.substr(maxIndex, maxLen);
    }
};