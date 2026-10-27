class Solution {
private:
    bool isPalindrome(const string& s, int left, int right) {
        if (left == right)
            return true;

        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }

        return true;
    }
    void solve(const string& s, vector<vector<string>>& answer,
               vector<string>& comb, int index) {
        if (index == s.size()) {
            answer.push_back(comb);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                comb.push_back(s.substr(index, i - index + 1));
                solve(s, answer, comb, i + 1);
                comb.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        vector<string> comb;
        solve(s, answer, comb, 0);

        return answer;
    }
};