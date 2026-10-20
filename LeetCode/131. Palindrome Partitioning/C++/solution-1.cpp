class Solution {
private:
    vector<vector<string>> answer;
    vector<string> sub;
    string comb;
    bool is_palindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }

        return true;
    }
    void part(string& s, int index) {
        if (index == s.size()) {
            answer.push_back(sub);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (is_palindrome(s, index, i)) {
                sub.push_back(s.substr(index, i - index + 1));
                part(s, i + 1);
                sub.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        part(s, 0);

        return answer;
    }
};