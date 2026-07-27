class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size(), left = 0, maxLen = 0;
        unordered_map<char, int> charIndices;

        for (int right = 0; right < size; right++) {
            if (charIndices.count(s[right]) && charIndices[s[right]] >= left)
                left = charIndices[s[right]] + 1;

            charIndices[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};