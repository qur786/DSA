class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost = 0, maxLen = 0, left = 0, size = s.size();

        for (int right = 0; right < size; right++) {
            cost += abs(s[right] - t[right]);
            if (maxCost < cost) {
                cost -= abs(s[left] - t[left]);
                left += 1;
            }

            if (cost <= maxCost)
                maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};