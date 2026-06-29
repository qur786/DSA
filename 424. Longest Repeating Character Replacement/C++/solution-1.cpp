class Solution {
public:
    int characterReplacement(string s, int k) {
        array<int, 26> sCount{};
        int left = 0, size = s.size(), maxLen = 0, maxOcc = 0;

        for (int right = 0; right < size; right++) {
            sCount[s[right] - 'A']++;
            maxOcc = max(maxOcc, sCount[s[right] - 'A']);

            if ((right - left + 1) > (maxOcc + k)) {
                sCount[s[left] - 'A']--;
                left += 1;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};