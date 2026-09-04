class Solution {
private:
    bool isSub(string& s, string& t, int i, int j) {
        if (t.size() == j && i == s.size())
            return true;
        if (t.size() == j && i < s.size())
            return false;

        if (s[i] == t[j])
            return isSub(s, t, i + 1, j + 1);

        return isSub(s, t, i, j + 1);
    }

public:
    bool isSubsequence(string s, string t) { return isSub(s, t, 0, 0); }
};