class Solution {
private:
    vector<vector<string>> answer;
    vector<string> comb;
    bool is_palindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left += 1;
            right -= 1;
        }
        return true;
    }
    void part(const string& s, int index) {
        if (index == s.size()) {
            answer.push_back(comb);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (is_palindrome(s, index, i)) {
                comb.push_back(s.substr(index, i - index + 1));
                part(s, i + 1);
                comb.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        part(s, 0);

        return answer;
    }
};