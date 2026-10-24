class Solution {
private:
    void solve(vector<int>& values, vector<bool>& visited, int& index) {
        if (index >= values.size())
            return;

        visited[index] = true;

        if (values[index] == -1)
            return;

        index += 1;
        solve(values, visited, index);
        index += 1;
        solve(values, visited, index);
    }

public:
    bool isValidSerialization(string preorder) {
        if (preorder == "#")
            return true;
        if (preorder[0] == '#')
            return false;
        string token;
        stringstream ss(preorder);
        vector<int> values;

        while (getline(ss, token, ',')) {
            if (token == "#")
                values.push_back(-1);
            else
                values.push_back(stoi(token));
        }

        int index = 0;
        vector<bool> visited(values.size(), false);
        solve(values, visited, index);

        bool isValid = none_of(visited.begin(), visited.end(),
                               [](bool val) { return !val; });

        return isValid && index == values.size() - 1;
    }
};