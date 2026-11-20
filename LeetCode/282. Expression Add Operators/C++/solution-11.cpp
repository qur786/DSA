class Solution {
private:
    void solve(string num, int target, vector<string>& answer,
               const string& comb, long long runningSum, long long prevNum,
               int size, int index) {
        if (index == size) {
            if (runningSum == target)
                answer.push_back(comb);
            return;
        }

        string numStr;
        long long n = 0;

        for (int i = index; i < size; i++) {
            if (!numStr.empty() && numStr[0] == '0') return;
            numStr.push_back(num[i]);
            n = n * 10 + num[i] - '0';
            if (index == 0) {
                solve(num, target, answer, comb + numStr, runningSum + n, n, size, i + 1);
            } else {
                solve(num, target, answer, comb + "+" + numStr, runningSum + n,
                      n, size, i + 1);
                solve(num, target, answer, comb + "-" + numStr, runningSum - n,
                      -n, size, i + 1);
                solve(num, target, answer, comb + "*" + numStr,
                      runningSum - prevNum + prevNum * n, prevNum * n, size,
                      i + 1);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        int size = num.size();
        vector<string> answer;
        solve(num, target, answer, "", 0, 0, size, 0);

        return answer;
    }
};