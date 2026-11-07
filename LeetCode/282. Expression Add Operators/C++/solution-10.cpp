class Solution {
private:
    void solve(const string& num, vector<string>& answer, const string& comb,
               long long runningSum, long long prevNum, int target, int size,
               int index) {
        if (index == size) {
            if (runningSum == target)
                answer.push_back(comb);
            return;
        }

        string numStr;
        long long n = 0;

        for (int i = index; i < size; i++) {
            if (!numStr.empty() && numStr[0] == '0')
                return;
            numStr.push_back(num[i]);
            n = n * 10 + (num[i] - '0');
            if (index == 0) {
                solve(num, answer, comb + numStr, runningSum + n, n, target,
                      size, i + 1);
            } else {
                solve(num, answer, comb + "+" + numStr, runningSum + n, n,
                      target, size, i + 1);
                solve(num, answer, comb + "-" + numStr, runningSum - n, -n,
                      target, size, i + 1);
                solve(num, answer, comb + "*" + numStr,
                      runningSum - prevNum + prevNum * n, n * prevNum, target,
                      size, i + 1);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> answer;
        int size = num.size();
        solve(num, answer, "", 0, 0, target, size, 0);
        return answer;
    }
};