class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndices;
        charIndices.reserve(128);
        int maxLen = 0, size = s.size(), left = 0;

        for (int i = 0; i < size; i++) {
            if (charIndices.count(s[i]) && charIndices[s[i]] >= left) {
                left = charIndices[s[i]] + 1;
            }
            charIndices[s[i]] = i;
            maxLen = max(maxLen, i - left + 1);
        }

        return maxLen;
    }
};