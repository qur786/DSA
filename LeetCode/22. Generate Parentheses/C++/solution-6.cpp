class Solution {
private:
    void solve(vector<string>& answer, string& comb, int n, int left,
               int right) {
        if (comb.size() == 2 * n) {
            answer.push_back(comb);
            return;
        }

        if (left < n) {
            comb.push_back('(');
            solve(answer, comb, n, left + 1, right);
            comb.pop_back();
        }
        if (right < left) {
            comb.push_back(')');
            solve(answer, comb, n, left, right + 1);
            comb.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string comb;
        solve(answer, comb, n, 0, 0);
        return answer;
    }
};