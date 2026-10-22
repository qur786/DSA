class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder == "#")
            return true;
        if (preorder[0] == '#')
            return false;

        vector<int> values;
        string token;
        stringstream ss(preorder);

        while (getline(ss, token, ',')) {
            if (token == "#")
                values.push_back(-1);
            else
                values.push_back(stoi(token));
        }

        int slots = 1;

        for (int i = 0; i < values.size(); i++) {
            slots -= 1;

            if (slots < 0)
                return false;

            if (values[i] != -1)
                slots += 2;
        }

        return slots == 0;
    }
};