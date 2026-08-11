class Solution {
public:
    string smallestPalindrome(string s) {
        int size = s.size();
        int mid = size / 2;
        array<int, 26> charCount{};
        int left = 0, right = size - 1;

        for (int i = 0; i < mid; i++)
            charCount[s[i] - 'a']++;

        for (int i = 0; i < 26; i++) {
            while (charCount[i] >= 1) {
                s[left] = 'a' + i;
                s[right] = 'a' + i;
                left++;
                right--;
                charCount[i]--;
            }
        }

        return s;
    }
};