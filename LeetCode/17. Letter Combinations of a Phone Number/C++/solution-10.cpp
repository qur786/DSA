class Solution {
private:
    unordered_map<char, string> letterMap = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };
    void solve(vector<string>& answer, string& comb, string& digits, int index,
               int size) {
        if (index == size) {
            if (comb.size() == size)
                answer.push_back(comb);
            return;
        }

        for (int i = index; i < size; i++) {
            for (char c : letterMap[digits[i]]) {
                comb.push_back(c);
                solve(answer, comb, digits, i + 1, size);
                comb.pop_back();
            }
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        string comb;
        int size = digits.size();
        solve(answer, comb, digits, 0, size);

        return answer;
    }
};