class Solution {
private:
    void solve(vector<vector<int>>& answer, vector<int>& comb, int n, int k,
               int num) {
        if (comb.size() == k) {
            answer.push_back(comb);
            return;
        }

        for (int i = num; i <= n; i++) {
            comb.push_back(i);
            solve(answer, comb, n, k, i + 1);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> answer;
        vector<int> comb;
        solve(answer, comb, n, k, 1);

        return answer;
    }
};