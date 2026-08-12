class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> st, ts;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            if (st.count(s[i]) ^ ts.count(t[i]))
                return false;
            if (!st.count(s[i]) && !ts.count(t[i])) {
                st[s[i]] = t[i];
                ts[t[i]] = s[i];
            } else if (st[s[i]] != t[i] || ts[t[i]] != s[i])
                return false;
        }

        return true;
    }
};