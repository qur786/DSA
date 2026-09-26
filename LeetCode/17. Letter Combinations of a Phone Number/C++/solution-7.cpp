class Solution {
private:
    vector<string> answer;
    string comb;
    unordered_map<char, string> letters = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };
    void createComb(string& digits, int size, int index) {
        if (comb.size() == size) {
            answer.push_back(comb);
            return;
        }

        for (int i = index; i < size; i++) {
            for (const char ch : letters[digits[i]]) {
                comb.push_back(ch);
                createComb(digits, size, i + 1);
                comb.pop_back();
            }
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        createComb(digits, digits.size(), 0);
        return answer;
    }
};