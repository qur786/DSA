class Solution {
private:
    unordered_map<char, string> letters = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };
    vector<string> answer;
    string comb;
    void genComb(string& digits, int index) {
        if (comb.size() == digits.size()) {
            answer.push_back(comb);
            return;
        }

        for (int i = index; i < digits.size(); i++) {
            for (char ch : letters[digits[i]]) {
                comb.push_back(ch);
                genComb(digits, i + 1);
                comb.pop_back();
            }
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        genComb(digits, 0);
        return answer;
    }
};