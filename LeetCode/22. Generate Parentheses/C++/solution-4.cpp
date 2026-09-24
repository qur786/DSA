class Solution {
private:
    void genParen(vector<string>& answer, string& comb, int leftCount,
                  int rightCount, int n, int size) {
        if (comb.size() == size) {
            answer.push_back(comb);
            return;
        }

        if (leftCount <= n) {
            comb.push_back('(');
            genParen(answer, comb, leftCount + 1, rightCount, n, size);
            comb.pop_back();
        }
        if (leftCount > rightCount) {
            comb.push_back(')');
            genParen(answer, comb, leftCount, rightCount + 1, n, size);
            comb.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string comb;
        genParen(answer, comb, 1, 1, n, 2 * n);

        return answer;
    }
};