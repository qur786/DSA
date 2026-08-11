class Solution {
public:
    int getLongestPalindrome(const string& s, int left, int right) {
        int maxlen = 0;
        while (left >= 0 && right < s.size()) {
            if (s[left] != s[right])
                break;
            maxlen = max(maxlen, right - left + 1);
            right++;
            left--;
        }
        return maxlen;
    }
    string longestPalindrome(string s) {
        int size = s.size(), maxlen = 0, maxindex = -1;
        for (int i = 0; i < size; i++) {
            int len1 = getLongestPalindrome(s, i, i);
            int len2 = getLongestPalindrome(s, i, i + 1);
            if (len1 > maxlen || len2 > maxlen) {
                maxlen = max(len1, len2);
                maxindex = i;
            }
        }

        return s.substr(maxindex - (maxlen - 1) / 2, maxlen);
    }
};