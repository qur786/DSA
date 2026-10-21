class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder == "#")
            return true;
        if (preorder[0] == '#')
            return false;

        int slots = 1;
        stringstream ss(preorder);
        string word;
        vector<string> tree;

        while (getline(ss, word, ',')) {
            slots -= 1;
            if (slots < 0)
                return false;

            if (word != "#")
                slots += 2;
        }

        return slots == 0;
    }
};