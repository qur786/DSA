class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> stMap, tsMap;
        int sSize = s.size();

        for (int i = 0; i < sSize; i++) {
            if (stMap.count(s[i]) ^ tsMap.count(t[i]))
                return false;
            if (stMap.count(s[i]) && tsMap.count(t[i]) &&
                (stMap[s[i]] != t[i] || tsMap[t[i]] != s[i]))
                return false;
            stMap[s[i]] = t[i];
            tsMap[t[i]] = s[i];
        }

        return true;
    }
};