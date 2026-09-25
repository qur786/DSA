class Solution {
private:
    bool isSub(string& s, string& t, int sindex, int tindex) {
        if (sindex == s.size())
            return true;
        if (tindex == t.size())
            return false;
        if (s[sindex] == t[tindex])
            return isSub(s, t, sindex + 1, tindex + 1);

        return isSub(s, t, sindex, tindex + 1);
    }

public:
    bool isSubsequence(string s, string t) { return isSub(s, t, 0, 0); }
};