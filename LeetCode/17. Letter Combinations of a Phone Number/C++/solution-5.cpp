class Solution {
private:
    void createComb(vector<string>& answer, string& comb, string& digits,
                    unordered_map<char, string>& chars, int size, int index) {
        if (comb.size() == size) {
            answer.push_back(comb);
            return;
        }

        for (int i = index; i < size; i++) {
            for (char c : chars[digits[i]]) {
                comb.push_back(c);
                createComb(answer, comb, digits, chars, size, i + 1);
                comb.pop_back();
            }
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        int size = digits.size();
        unordered_map<char, string> chars = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
        };
        string comb;
        vector<string> answer;

        createComb(answer, comb, digits, chars, size, 0);

        return answer;
    }
};