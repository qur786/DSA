class Solution {
public:
    int longestSubstring(string s, int k) {
        int size = s.size(), maxLen = 0;

        for (int count = 26; count >= 1; count--) {
            if (size < count)
                continue;
            unordered_map<char, int> charCount;
            int left = 0, matchedChars = 0;
            for (int right = 0; right < size; right++) {
                charCount[s[right]]++;
                if (charCount[s[right]] == k)
                    matchedChars++;

                while (charCount.size() > count) {
                    if (charCount[s[left]] == k)
                        matchedChars--;
                    charCount[s[left]]--;
                    if (charCount[s[left]] == 0)
                        charCount.erase(s[left]);
                    left++;
                }

                if (matchedChars == count)
                    maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }
};