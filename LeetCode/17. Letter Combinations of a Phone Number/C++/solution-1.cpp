class Solution {
private:
    void createComb(vector<string>& answer, string& digits,
                    vector<string>& combinations, string& comb, int size,
                    int index) {
        if (comb.size() == size) {
            answer.push_back(comb);
            return;
        }

        for (int i = index; i < size; i++) {
            for (char c : combinations[digits[i] - '2']) {
                comb.push_back(c);
                createComb(answer, digits, combinations, comb, size, i + 1);
                comb.pop_back();
            }
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        string comb;
        vector<string> combinations = {"abc", "def",  "ghi", "jkl",
                                       "mno", "pqrs", "tuv", "wxyz"};
        int size = digits.size();
        createComb(answer, digits, combinations, comb, size, 0);

        return answer;
    }
};