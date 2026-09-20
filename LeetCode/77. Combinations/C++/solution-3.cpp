class Solution {
private:
    void createComb(vector<vector<int>>& answer, vector<int>& sub,
                    vector<bool>& visited, int index, int n, int k) {
        if (k == sub.size()) {
            answer.push_back(sub);
            return;
        }

        for (int i = index; i <= n; i++) {
            if (visited[i])
                continue;
            sub.push_back(i);
            visited[i] = true;
            createComb(answer, sub, visited, i + 1, n, k);
            sub.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> answer;
        vector<int> sub;
        vector<bool> visited(n, false);
        createComb(answer, sub, visited, 1, n, k);

        return answer;
    }
};