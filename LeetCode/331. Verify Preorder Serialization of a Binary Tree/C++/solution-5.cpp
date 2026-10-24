class Solution {
private:
    bool solve(vector<int>& values) {
        int slotCount = 1;

        for (int i = 0; i < values.size(); i++) {
            slotCount -= 1;

            if (slotCount < 0)
                return false;

            if (values[i] != -1)
                slotCount += 2;
        }

        return slotCount == 0;
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

        return solve(values);
    }
};