class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> frogsNeeded = {
            {'c', 0},
            {'r', 0},
            {'o', 0},
            {'a', 0},
        };
        unordered_map<char, char> letterMap = {
            {'r', 'c'},
            {'o', 'r'},
            {'a', 'o'},
            {'k', 'a'},
        };
        int maxFrogs = 0;
        int currentFrogs = 0;

        for (char c : croakOfFrogs) {
            if (c == 'c') {
                frogsNeeded[c]++;
                currentFrogs++;
            } else if (c == 'k') {
                if (frogsNeeded['a'] > 0) {
                    frogsNeeded['a']--;
                    currentFrogs--;
                } else
                    return -1;
            } else {
                if (frogsNeeded[letterMap[c]] > 0) {
                    frogsNeeded[letterMap[c]]--;
                    frogsNeeded[c]++;
                } else
                    return -1;
            }
            maxFrogs = max(maxFrogs, currentFrogs);
        }

        return currentFrogs > 0 ? -1 : maxFrogs;
    }
};