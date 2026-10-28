class Solution {
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
};