class Solution {
private:
    bool checkSubsequence(string& s, string& t, int i, int j) {
        if (i == s.size())
            return true;
        if (j == t.size())
            return false;
        bool result = false;
        return checkSubsequence(s, t, s[i] == t[j] ? i + 1 : i, j + 1);
    }

public:
    bool isSubsequence(string s, string t) {
        return checkSubsequence(s, t, 0, 0);
    }
};