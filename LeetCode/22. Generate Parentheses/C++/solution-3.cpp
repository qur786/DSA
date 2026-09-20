class Solution {
private:
    void genParen(int n, vector<string>& answer, string& sub, int leftCount,
                  int rightCount) {
        if (sub.size() == 2 * n) {
            answer.push_back(sub);
            return;
        }

        if (leftCount < n) {
            sub.push_back('(');
            genParen(n, answer, sub, leftCount + 1, rightCount);
            sub.pop_back();
        }

        if (leftCount > rightCount) {
            sub.push_back(')');
            genParen(n, answer, sub, leftCount, rightCount + 1);
            sub.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string sub;
        genParen(n, answer, sub, 0, 0);

        return answer;
    }
};