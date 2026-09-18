class Solution {
private:
    void getCom(vector<string>& answer, string& digits, string& sub,
                vector<string>& chars, int size, int index) {
        if (sub.size() == size) {
            answer.push_back(sub);
            return;
        }

        for (int i = index; i < size; i++) {
            for (int j = 0; j < chars[digits[i] - '2'].size(); j++) {
                sub.push_back(chars[digits[i] - '2'][j]);
                getCom(answer, digits, sub, chars, size, i + 1);
                sub.pop_back();
            }
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> chars = {"abc", "def",  "ghi", "jkl",
                                "mno", "pqrs", "tuv", "wxyz"};
        int size = digits.size();
        vector<string> answer;
        string sub;
        getCom(answer, digits, sub, chars, size, 0);
        return answer;
    }
};