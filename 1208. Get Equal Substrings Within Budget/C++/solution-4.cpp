class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost = 0, size = s.size(), maxLen = 0, left = 0;

        for (int right = 0; right < size; right++) {
            cost += abs(s[right] - t[right]);
            while (cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};