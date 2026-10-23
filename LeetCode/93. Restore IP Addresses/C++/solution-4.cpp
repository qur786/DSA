class Solution {
private:
    bool isValid(const string& s) {
        if (s.size() >= 2 && s[0] == '0')
            return false;

        return stoi(s) <= 255;
    }
    void solve(const string& s, vector<string>& answer, const string& path,
               int index, int fullfilled) {
        if (index == s.size()) {
            if (fullfilled == 4)
                answer.push_back(path);
            return;
        }

        if (fullfilled >= 4)
            return;

        int limit = min(index + 3, (int)s.size());

        for (int i = index; i < limit; i++) {
            string sub = s.substr(index, i - index + 1);
            if (isValid(sub)) {
                solve(s, answer, path == "" ? sub : path + "." + sub, i + 1,
                      fullfilled + 1);
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> answer;
        string path;
        solve(s, answer, path, 0, 0);

        return answer;
    }
};