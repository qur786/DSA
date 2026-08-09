class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.size() < 2)
            return "";

        unordered_set<char> charSet(s.begin(), s.end());
        int size = s.size();

        for (int i = 0; i < size; i++) {
            if (!charSet.count(toupper(s[i])) ||
                !charSet.count(tolower(s[i]))) {
                string str1 = longestNiceSubstring(s.substr(0, i));
                string str2 = longestNiceSubstring(s.substr(i + 1));

                return str1.size() >= str2.size() ? str1 : str2;
            }
        }

        return s;
    }
};