class Solution {
public:
    int longestAwesome(string s) {
        int mask = 0;
        int size = s.size();
        int maxLen = 0;
        unordered_map<int, int> maskMap = {{0, -1}};

        for (int i = 0; i < size; i++) {
            mask = mask ^ (1 << (s[i] - '0'));

            if (maskMap.count(mask))
                maxLen = max(maxLen, i - maskMap[mask]);
            else
                maskMap[mask] = i;

            for (int j = 0; j < 10; j++) {
                int key = mask ^ (1 << j);
                if (maskMap.count(key))
                    maxLen = max(maxLen, i - maskMap[key]);
            }
        }

        return maxLen;
    }
};