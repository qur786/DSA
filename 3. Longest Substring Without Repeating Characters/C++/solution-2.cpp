class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndices;
        int left = 0, size = s.size(), maxLen = 0;

        for (int right = 0; right < size; right++) {
            if (charIndices.count(s[right]) && charIndices[s[right]] >= left) {
                left = charIndices[s[right]] + 1;
            }
            charIndices[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};