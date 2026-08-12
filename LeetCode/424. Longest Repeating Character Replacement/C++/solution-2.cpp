class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, size = s.size(), maxLen = 0;
        unordered_map<char, int> charCount;
        charCount.reserve(26);
        int maxCount = 0;

        for (int right = 0; right < size; right++) {
            charCount[s[right]]++;
            maxCount = max(maxCount, charCount[s[right]]);
            if ((right - left + 1) > (maxCount + k)) {
                charCount[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};