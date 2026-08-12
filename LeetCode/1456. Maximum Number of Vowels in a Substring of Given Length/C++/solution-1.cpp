class Solution {
public:
    bool isVowel(char c) {
        switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int left = 0, size = s.size(), maxVowelCount = 0, vowelCount = 0;

        for (int right = 0; right < size; right++) {
            if (isVowel(s[right]))
                vowelCount++;

            if ((right - left + 1) > k) {
                if (isVowel(s[left]))
                    vowelCount--;
                left++;
            }

            maxVowelCount = max(vowelCount, maxVowelCount);
        }

        return maxVowelCount;
    }
};