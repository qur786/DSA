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
        unordered_map<string, int> wordMap;
        vector<vector<int>> result;

        for (int i = 0; i < words.size(); i++) {
            wordMap[words[i]] = i;
        }

        for (int w = 0; w < words.size(); w++) {
            string word = words[w];
            int size = word.size();
            for (int i = 1; i <= size; i++) {
                if (!isPalindrome(word, 0, i - 1))
                    continue;
                string rightSubString = word.substr(i);
                reverse(rightSubString.begin(), rightSubString.end());
                if (wordMap.count(rightSubString) &&
                    wordMap[rightSubString] != w)
                    result.push_back({wordMap[rightSubString], w});
            }
            for (int i = 0; i <= size; i++) {
                if (!isPalindrome(word, i, size - 1))
                    continue;
                string leftSubString = word.substr(0, i);
                reverse(leftSubString.begin(), leftSubString.end());
                if (wordMap.count(leftSubString) && wordMap[leftSubString] != w)
                    result.push_back({w, wordMap[leftSubString]});
            }
        }

        return result;
    }
};