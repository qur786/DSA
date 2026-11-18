class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder == "#")
            return true;
        if (preorder[0] == '#')
            return false;

        int slots = 1;

        stringstream ss(preorder);
        string token;

        while (getline(ss, token, ',')) {
            slots -= 1;

            if (slots < 0)
                return false;

            if (token[0] != '#')
                slots += 2;
        }

        return slots == 0;
    }
};