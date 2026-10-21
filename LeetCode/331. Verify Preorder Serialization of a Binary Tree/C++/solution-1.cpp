class Solution {
private:
    void checkValidity(vector<int>& values, vector<bool>& visited, int& index) {
        if (index >= values.size())
            return;

        if (visited[index])
            return;

        int currIndex = index;
        visited[currIndex] = true;

        if (values[index] == -1) {
            return;
        }

        index++;
        checkValidity(values, visited, index);
        index++;
        checkValidity(values, visited, index);
    }

public:
    bool isValidSerialization(string preorder) {
        if (preorder == "#")
            return true;
        if (preorder[0] == '#')
            return false;

        stringstream ss(preorder);
        string word;
        vector<int> values;

        while (getline(ss, word, ',')) {
            values.push_back(word == "#" ? -1 : stoi(word));
        }
        vector<bool> visited(values.size(), false);
        int index = 0;

        checkValidity(values, visited, index);

        bool isValid = none_of(visited.begin(), visited.end(),
                               [](bool val) { return !val; });

        return isValid && (index == values.size() - 1);
    }
};