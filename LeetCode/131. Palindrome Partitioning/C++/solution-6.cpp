class Solution {
private:
    bool is_palindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    void solve(vector<vector<string>>& answer, vector<string>& comb, string& s,
               int index, int size) {
        if (index == size) {
            answer.push_back(comb);
            return;
        }

        for (int i = index; i < size; i++) {
            if (!is_palindrome(s, index, i))
                continue;
            string sub = s.substr(index, i - index + 1);
            comb.push_back(sub);
            solve(answer, comb, s, i + 1, size);
            comb.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int size = s.size();
        vector<vector<string>> answer;
        vector<string> comb;
        solve(answer, comb, s, 0, size);
        return answer;
    }
};