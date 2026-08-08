class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> sSet, tSet;

        for (char c : s)
            sSet[c]++;
        for (char c : t)
            tSet[c]++;

        return sSet == tSet;
    }
};