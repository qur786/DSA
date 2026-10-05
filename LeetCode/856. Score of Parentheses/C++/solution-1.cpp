class Solution {
public:
    int scoreOfParentheses(string s) {
        int size = s.size();
        int level = 0;
        int score = 0;

        for (int i = 0; i < size; i++) {
            if (s[i] == '(') {
                level++;
            } else {
                level--;
                if (s[i - 1] == '(')
                    score += pow(2, level);
            }
        }
        return score;
    }
};