class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }

        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wordsMap;
        vector<vector<int>> result;
        int size = words.size();

        for (int i = 0; i < size; i++) {
            wordsMap[words[i]] = i;
        }

        for (int curr = 0; curr < size; curr++) {
            const string& word = words[curr];
            int wordSize = word.size();
            for (int i = 1; i <= wordSize; i++) {
                string rightString = word.substr(i);
                if (isPalindrome(word, 0, i - 1)) {
                    reverse(rightString.begin(), rightString.end());
                    if (wordsMap.count(rightString) &&
                        wordsMap[rightString] != curr) {
                        result.push_back({wordsMap[rightString], curr});
                    }
                }
            }
            for (int i = 0; i <= wordSize; i++) {
                string leftString = word.substr(0, i);
                if (isPalindrome(word, i, wordSize - 1)) {
                    reverse(leftString.begin(), leftString.end());
                    if (wordsMap.count(leftString) &&
                        wordsMap[leftString] != curr) {
                        result.push_back({curr, wordsMap[leftString]});
                    }
                }
            }
        }

        return result;
    }
};