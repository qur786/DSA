class Solution {
private:
    void solve(vector<string>& answer, string& comb, int n, int size,
               int leftCount, int rightCount) {
        if (comb.size() == size) {
            answer.push_back(comb);
            return;
        }

        if (leftCount < n) {
            comb.push_back('(');
            solve(answer, comb, n, size, leftCount + 1, rightCount);
            comb.pop_back();
        }

        if (rightCount < leftCount) {
            comb.push_back(')');
            solve(answer, comb, n, size, leftCount, rightCount + 1);
            comb.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string comb;
        int size = 2 * n;
        solve(answer, comb, n, size, 0, 0);

        return answer;
    }
};