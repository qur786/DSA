class Solution {
private:
    bool isPalindrome(const string& s, int left, int right) {
        if (left >= right)
            return true;

        while (left < right) {
            if (s[left] != s[right])
                return false;
            left += 1;
            right -= 1;
        }

        return true;
    }
    void solve(const string& s, vector<vector<string>>& answer,
               vector<string>& path, int index) {
        if (index == s.size()) {
            answer.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                solve(s, answer, path, i + 1);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        vector<string> path;
        solve(s, answer, path, 0);

        return answer;
    }
};