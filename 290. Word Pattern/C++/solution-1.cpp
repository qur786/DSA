class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> strToCharMap;
        unordered_map<char, string> charToStrMap;

        stringstream ss(s);
        string word;

        int size = pattern.size(), i = 0;

        while (ss >> word) {
            if (!strToCharMap.count(word) ^ !charToStrMap.count(pattern[i]))
                return false;
            if (strToCharMap.count(word) && charToStrMap.count(pattern[i]) &&
                (strToCharMap[word] != pattern[i] ||
                 charToStrMap[pattern[i]] != word))
                return false;

            strToCharMap[word] = pattern[i];
            charToStrMap[pattern[i]] = word;
            i++;
        }

        return i == size;
    }
};