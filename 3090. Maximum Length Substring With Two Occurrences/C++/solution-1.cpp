class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0, size = s.size(), maxLen = 0;
        array<int, 26> charMap{};

        for (int right = 0; right < size; right++) {
            charMap[s[right] - 'a']++;
            while (charMap[s[right] - 'a'] > 2) {
                charMap[s[left] - 'a']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};