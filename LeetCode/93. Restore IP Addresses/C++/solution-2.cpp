class Solution {
private:
    vector<string> answer;
    bool isValid(const string& s) {
        if (s.empty())
            return false;
        if (s.size() >= 2 && s[0] == '0')
            return false;
        return stoi(s) <= 255;
    }
    void restore(const string& s, const string& pattern, int index,
                 int patternCount) {
        if (patternCount > 4)
            return;
        if (index == s.size()) {
            if (patternCount == 4)
                answer.push_back(pattern);
            return;
        }

        int limit = min(index + 3, (int)s.size());

        for (int i = index; i < limit; i++) {
            string subS = s.substr(index, i - index + 1);
            if (isValid(subS)) {
                restore(s, pattern.empty() ? subS : (pattern + "." + subS),
                        i + 1, patternCount + 1);
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        restore(s, "", 0, 0);
        return answer;
    }
};