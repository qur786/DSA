class Solution {
public:
    int longestAwesome(string s) {
        int size = s.size();

        unordered_map<int, int> maskMap = {{0, -1}};
        int mask = 0, maxLen = 0;

        for (int i = 0; i < size; i++) {
            mask = mask ^ (1 << (s[i] - '0'));
            if (maskMap.count(mask))
                maxLen = max(maxLen, i - maskMap[mask]);
            else
                maskMap[mask] = i;

            for (int j = 0; j < 10; j++) {
                int mask2 = mask ^ (1 << j);
                if (maskMap.count(mask2)) {
                    maxLen = max(maxLen, i - maskMap[mask2]);
                }
            }
        }

        return maxLen;
    }
};