class Solution {
private:
    vector<string> answer;
    vector<string> sub;
    bool isValid(const string& s) {
        if (s.empty())
            return false;
        if (s.size() >= 2 && s[0] == '0')
            return false;
        return stoi(s) <= 255;
    }
    string joinIP(vector<string>& ips) {
        string result;

        for (int i = 0; i < ips.size() - 1; i++) {
            result.append(ips[i]);
            result.append(".");
        }

        result.append(ips.back());

        return result;
    }
    void restore(const string& s, int index) {
        if (sub.size() > 4)
            return;
        if (index == s.size()) {
            if (sub.size() == 4)
                answer.push_back(joinIP(sub));
            return;
        }

        int limit = min(index + 3, (int)s.size());

        for (int i = index; i < limit; i++) {
            string subS = s.substr(index, i - index + 1);
            if (isValid(subS)) {
                sub.push_back(subS);
                restore(s, i + 1);
                sub.pop_back();
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        restore(s, 0);

        return answer;
    }
};