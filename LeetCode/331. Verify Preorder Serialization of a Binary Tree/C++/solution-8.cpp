class Solution {
private:
    bool solve(vector<int>& values, int& index) {
        if (index >= values.size())
            return false;

        if (values[index] == -1)
            return true;

        index += 1;
        if (!solve(values, index))
            return false;
        index += 1;
        if (!solve(values, index))
            return false;

        return true;
    }

public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string token;
        vector<int> values;

        while (getline(ss, token, ',')) {
            if (token == "#")
                values.push_back(-1);
            else
                values.push_back(stoi(token));
        }

        int index = 0;
        bool res = solve(values, index);
        return res && index == values.size() - 1;
    }
};