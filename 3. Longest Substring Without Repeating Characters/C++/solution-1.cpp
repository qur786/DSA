class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, size = s.size(), maxLen = 0;
        vector<int> charIndices(128, -1);

        for (int right = 0; right < size; right++) {
            if (charIndices[s[right]] >= left) {
                left = charIndices[s[right]] + 1;
            }
            charIndices[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};