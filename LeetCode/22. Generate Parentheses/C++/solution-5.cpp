class Solution {
private:
    vector<string> answer;
    string comb;
    void genParen(int n, int newSize, int left, int right) {
        if (newSize == comb.size()) {
            answer.push_back(comb);
            return;
        }

        if (left < n) {
            comb.push_back('(');
            genParen(n, newSize, left + 1, right);
            comb.pop_back();
        }
        if (right < left) {
            comb.push_back(')');
            genParen(n, newSize, left, right + 1);
            comb.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        genParen(n, 2 * n, 0, 0);

        return answer;
    }
};