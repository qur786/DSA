class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxLen = 0, left = 0, size = s.size(), cost = 0;

        for (int right = 0; right < size; right++) {
            cost += abs(s[right] - t[right]);

            if (cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};