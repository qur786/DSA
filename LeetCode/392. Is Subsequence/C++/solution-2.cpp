class Solution {
private:
    bool checkSubseq(const string& s, const string& t, int i, int j) {
        if (i == s.size())
            return true;
        if (i < s.size() && j == t.size())
            return false;

        return checkSubseq(s, t, s[i] == t[j] ? i + 1 : i, j + 1);
    }

public:
    bool isSubsequence(string s, string t) { return checkSubseq(s, t, 0, 0); }
};