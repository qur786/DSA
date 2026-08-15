class Solution {
public:
    int takeCharacters(string s, int k) {
        int maxLen = INT_MIN;
        int size = s.size();
        int left = 0;
        array<int, 3> charCount;

        for (char c : s)
            charCount[c - 'a']++;

        for (int count : charCount)
            if (count < k)
                return -1;

        for (int right = 0; right < size; right++) {
            charCount[s[right] - 'a']--;

            while (left <= right && charCount[s[right] - 'a'] < k) {
                charCount[s[left] - 'a']++;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return size - maxLen;
    }
};