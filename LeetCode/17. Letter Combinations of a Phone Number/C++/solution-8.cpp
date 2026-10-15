class Solution {
private:
    vector<string> answer;
    string comb;
    unordered_map<char, string> letterMap = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };
    void genComb(string& digits, int size, int index) {
        if (comb.size() == size) {
            answer.push_back(comb);
            return;
        }

        for (int i = index; i < size; i++) {
            for (char ch : letterMap[digits[i]]) {
                comb.push_back(ch);
                genComb(digits, size, i + 1);
                comb.pop_back();
            }
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        genComb(digits, digits.size(), 0);

        return answer;
    }
};