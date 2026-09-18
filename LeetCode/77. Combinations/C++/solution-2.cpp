class Solution {
private:
    void createComb(vector<vector<int>>& answer, vector<int>& sub,
                    vector<bool>& visited, int n, int k, int index) {
        if (sub.size() == k) {
            answer.push_back(sub);
            return;
        }

        for (int i = index; i <= n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                sub.push_back(i);
                createComb(answer, sub, visited, n, k, i + 1);
                visited[i] = false;
                sub.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> answer;
        vector<bool> visited(n + 1, false);
        vector<int> sub;
        createComb(answer, sub, visited, n, k, 1);

        return answer;
    }
};