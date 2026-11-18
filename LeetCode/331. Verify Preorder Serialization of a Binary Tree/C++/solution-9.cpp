class Solution {
private:
    void solve(vector<char>& preorder, vector<bool>& visited, int size,
               int& index) {
        if (index >= size)
            return;

        if (visited[index])
            return;

        visited[index] = true;
        if (preorder[index] == '#')
            return;

        index += 1;
        solve(preorder, visited, size, index);
        index += 1;
        solve(preorder, visited, size, index);
    }

public:
    bool isValidSerialization(string preorder) {
        vector<char> pre;
        int index = 0;

        stringstream ss(preorder);
        string token;

        while (getline(ss, token, ',')) {
            pre.push_back(token[0]);
        }
        int size = pre.size();
        vector<bool> visited(size, false);

        solve(pre, visited, size, index);

        bool isValid = none_of(visited.begin(), visited.end(),
                               [](bool val) { return !val; });

        return isValid && index == size - 1;
    }
};