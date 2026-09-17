class Solution {
private:
    void createComb(vector<vector<int>>& answer, vector<int>& curr,
                    vector<bool>& visited, int n, int k, int index) {
        if (curr.size() == k) {
            answer.push_back(curr);
            return;
        }

        for (int i = index; i <= n; i++) {
            if (!visited[i]) {
                curr.push_back(i);
                visited[i] = true;
                createComb(answer, curr, visited, n, k, i + 1);
                curr.pop_back();
                visited[i] = false;
            }
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> answer;
        vector<int> curr;
        vector<bool> visited(n, false);
        createComb(answer, curr, visited, n, k, 1);

        return answer;
    }
};