class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, size = s.size(), maxFreq = 0, maxLen = 0;
        array<int, 26> charCount{};

        for (int right = 0; right < size; right++) {
            charCount[s[right] - 'A']++;
            maxFreq = max(maxFreq, charCount[s[right] - 'A']);

            if ((right - left + 1) > (maxFreq + k)) {
                charCount[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};