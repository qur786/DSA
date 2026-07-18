class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int totalFrogs = 0, minFrogs = -1;
        unordered_map<char, int> frogs = {
            {'c', 0},
            {'r', 0},
            {'o', 0},
            {'a', 0},
        };
        unordered_map<char, char> prevFrog = {
            {'k', 'a'},
            {'a', 'o'},
            {'o', 'r'},
            {'r', 'c'},
        };
        int size = croakOfFrogs.size();

        for (int i = 0; i < size; i++) {
            char c = croakOfFrogs[i];
            if (c != 'c' && frogs[prevFrog[c]] == 0)
                return -1;
            if (c == 'c')
                totalFrogs++;
            else
                frogs[prevFrog[c]]--;
            if (c == 'k')
                totalFrogs--;
            else
                frogs[c]++;
            minFrogs = max(minFrogs, totalFrogs);
        }

        for (const auto& [key, count] : frogs)
            if (count > 0)
                return -1;

        return minFrogs;
    }
};