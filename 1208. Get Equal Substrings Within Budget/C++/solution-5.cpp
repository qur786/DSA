class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0, maxLen = 0, size = s.size();

        for (int right = 0; right < size; right++) {
            maxCost -= abs(t[right] - s[right]);

            while (left <= right && maxCost < 0) {
                maxCost += abs(t[left] - s[left]);
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};