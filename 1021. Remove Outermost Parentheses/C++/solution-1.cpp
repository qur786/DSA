class Solution {
public:
    string removeOuterParentheses(string s) {
        int stackDepth = 1;
        string result;

        for (const char& c : s) {
            if (c == '(') {
                if (stackDepth > 1)
                    result.push_back(c);
                stackDepth++;
            } else {
                stackDepth--;
                if (stackDepth > 1)
                    result.push_back(c);
            }
        }

        return result;
    }
};