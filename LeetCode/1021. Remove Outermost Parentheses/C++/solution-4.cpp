class Solution {
public:
    string removeOuterParentheses(string s) {
        int level = 0;
        int size = s.size();
        string answer;
        answer.reserve(size);

        for (int i = 0; i < size; i++) {
            if (s[i] == '(') {
                if (level != 0)
                    answer.push_back(s[i]);
                level++;
            } else {
                level--;
                if (level != 0)
                    answer.push_back(s[i]);
            }
        }

        return answer;
    }
};