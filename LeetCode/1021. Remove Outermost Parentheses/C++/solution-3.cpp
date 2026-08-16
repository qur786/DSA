class Solution {
public:
    string removeOuterParentheses(string s) {
        int level = 0;
        string result;

        for (char c : s)
            if (c == '(') {
                if (level != 0)
                    result.push_back(c);
                level++;
            } else {
                level--;
                if (level != 0)
                    result.push_back(c);
            }
        return result;
    }
};