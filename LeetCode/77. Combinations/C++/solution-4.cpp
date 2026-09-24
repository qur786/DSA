class Solution {
private:
    void createComb(vector<vector<int>>& answer, vector<int>& comb, int n,
                    int k, int index) {
        if (comb.size() == k) {
            answer.push_back(comb);
            return;
        }

        for (int i = index; i <= n; i++) {
            comb.push_back(i);
            createComb(answer, comb, n, k, i + 1);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        vector<vector<int>> answer;
        createComb(answer, comb, n, k, 1);

        return answer;
    }
};