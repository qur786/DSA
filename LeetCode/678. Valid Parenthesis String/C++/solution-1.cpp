class Solution {
public:
    bool checkValidString(string s) {
        stack<char> paren, aster;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            if (s[i] == '(')
                paren.push(i);
            else if (s[i] == ')') {
                if (!paren.empty())
                    paren.pop();
                else if (!aster.empty())
                    aster.pop();
                else
                    return false;
            } else
                aster.push(i);
        }

        while (!paren.empty() && !aster.empty() && paren.top() < aster.top()) {
            paren.pop();
            aster.pop();
        }

        return paren.empty();
    }
};