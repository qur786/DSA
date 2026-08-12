class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> uniqueSet;
        uniqueSet.reserve(26);

        for (char c : s)
            uniqueSet[c]++;

        for (int i = 0; i < s.size(); i++)
            if (uniqueSet[s[i]] == 1)
                return i;

        return -1;
    }
};