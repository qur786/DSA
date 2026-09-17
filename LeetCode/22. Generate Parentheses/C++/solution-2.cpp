class Solution {
private:
    void genParen(vector<string>& answer, string& comb, int n, int leftCount,
                  int rightCount) {
        if (comb.size() == 2 * n) {
            answer.push_back(comb);
            return;
        }

        if (leftCount < n) {
            comb.push_back('(');
            genParen(answer, comb, n, leftCount + 1, rightCount);
            comb.pop_back();
        }

        if (leftCount > rightCount) {
            comb.push_back(')');
            genParen(answer, comb, n, leftCount, rightCount + 1);
            comb.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string comb;
        genParen(answer, comb, n, 0, 0);

        return answer;
    }
};