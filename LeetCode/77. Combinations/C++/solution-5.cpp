class Solution {
private:
    vector<vector<int>> answer;
    vector<int> comb;
    void genComb(int n, int k, int index) {
        if (comb.size() == k) {
            answer.push_back(comb);
            return;
        }

        for (int i = index; i <= n; i++) {
            comb.push_back(i);
            genComb(n, k, i + 1);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        genComb(n, k, 1);

        return answer;
    }
};