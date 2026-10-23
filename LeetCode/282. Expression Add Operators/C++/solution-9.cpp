class Solution {
private:
    void solve(const string& num, int target, int index, int size,
               vector<string>& answer, const string& comb, long long runningSum,
               long long prevNum) {
        if (index == size) {
            if (runningSum == target)
                answer.push_back(comb);
            return;
        }

        string numStr;
        long long value = 0;
        for (int i = index; i < size; i++) {
            if (i > index && num[index] == '0')
                return;
            numStr.push_back(num[i]);
            value = value * 10 + num[i] - '0';
            if (comb.empty()) {
                solve(num, target, i + 1, size, answer, numStr, value, value);
            } else {
                solve(num, target, i + 1, size, answer, comb + "+" + numStr,
                      runningSum + value, value);
                solve(num, target, i + 1, size, answer, comb + "-" + numStr,
                      runningSum - value, -value);
                solve(num, target, i + 1, size, answer, comb + "*" + numStr,
                      runningSum - prevNum + value * prevNum, value * prevNum);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> answer;
        solve(num, target, 0, num.size(), answer, "", 0, 0);

        return answer;
    }
};