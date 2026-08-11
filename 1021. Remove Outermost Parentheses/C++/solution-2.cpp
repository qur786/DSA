class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int level = 0;

        for (char c : s) {
            if (c == '(') {
                level++;
                if (level > 1)
                    result.push_back(c);
            } else if (c == ')') {
                if (level > 1)
                    result.push_back(c);
                level--;
            }
        }

        return result;
    }
};