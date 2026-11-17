class Solution {
private:
    bool isValid(string& s) {
        if (s.size() > 1 && s[0] == '0')
            return false;

        return stoi(s) <= 255;
    }
    void solve(vector<string>& answer, const string& comb, string& s, int index,
               int fullfilled, int size) {
        if (index == size) {
            if (fullfilled == 4)
                answer.push_back(comb);
            return;
        }
        if (fullfilled >= 4)
            return;

        int limit = min(index + 3, size);

        for (int i = index; i < limit; i++) {
            string sub = s.substr(index, i - index + 1);
            if (!isValid(sub))
                continue;
            solve(answer, comb.empty() ? sub : comb + "." + sub, s, i + 1,
                  fullfilled + 1, size);
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> answer;
        string comb;
        int size = s.size();
        solve(answer, comb, s, 0, 0, size);
        return answer;
    }
};