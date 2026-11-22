class Solution {
public:
    bool checkString(string s) {
        bool isB = false;

        for (char c : s) {
            if (c == 'a') {
                if (isB)
                    return false;
            } else
                isB = true;
        }

        return true;
    }
};