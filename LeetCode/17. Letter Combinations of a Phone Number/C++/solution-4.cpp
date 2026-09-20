class Solution {
private:
    void createComb(vector<string>& answer, string& comb, string& digits,
                    unordered_map<char, string>& chars, int index, int size) {
        if (comb.size() == size) {
            answer.push_back(comb);
            return;
        }

        for (int i = index; i < size; i++) {
            for (char c : chars[digits[i]]) {
                comb.push_back(c);
                createComb(answer, comb, digits, chars, i + 1, size);
                comb.pop_back();
            }
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        string comb;
        unordered_map<char, string> chars = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
        };
        int size = digits.size();
        createComb(answer, comb, digits, chars, 0, size);

        return answer;
    }
};