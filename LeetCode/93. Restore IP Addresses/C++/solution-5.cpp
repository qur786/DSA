class Solution {
private:
    bool isValid(const string& s) {
        if (s.size() >= 2 && s[0] == '0')
            return false;

        return stoi(s) <= 255;
    }
    void solve(const string& s, const string& comb, vector<string>& answer,
               int index, int count) {
        if (index == s.size()) {
            if (count == 4) {
                answer.push_back(comb);
            }
            return;
        }

        if (count >= 4)
            return;

        int limit = min(index + 3, (int)s.size());

        for (int i = index; i < limit; i++) {
            const string sub = s.substr(index, i - index + 1);
            if (isValid(sub)) {
                solve(s, comb.empty() ? sub : comb + "." + sub, answer, i + 1,
                      count + 1);
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> answer;
        solve(s, "", answer, 0, 0);

        return answer;
    }
};