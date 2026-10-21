class Solution {
private:
    bool isValid(const string& s) {
        if (s.size() >= 2 && s[0] == '0')
            return false;

        return stoi(s) <= 255;
    }
    vector<string> answer;
    void restore(const string& s, const string& comb, int index,
                 int partCount) {
        if (partCount > 4)
            return;
        if (partCount == 4 && index == s.size()) {
            answer.push_back(comb);
            return;
        }

        int limit = min(index + 3, (int)s.size());

        for (int i = index; i < limit; i++) {
            string val = s.substr(index, i - index + 1);
            if (isValid(val)) {
                restore(s, comb.empty() ? val : comb + "." + val, i + 1,
                        partCount + 1);
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        restore(s, "", 0, 0);

        return answer;
    }
};