class Solution {
private:
    vector<string> answer;
    void addOp(string& num, const string& comb, int target,
               long long resultSoFar, long long prevNum, int index) {
        if (index == num.size()) {
            if (resultSoFar == target)
                answer.push_back(comb);

            return;
        }

        string numStr;
        long long value = 0;

        for (int i = index; i < num.size(); i++) {
            if (i > index && num[index] == '0')
                return;
            value = value * 10 + num[i] - '0';
            numStr.push_back(num[i]);
            if (index == 0)
                addOp(num, comb + numStr, target, value, value, i + 1);
            else {
                addOp(num, comb + "+" + numStr, target, resultSoFar + value,
                      value, i + 1);
                addOp(num, comb + "-" + numStr, target, resultSoFar - value,
                      -value, i + 1);
                addOp(num, comb + "*" + numStr, target,
                      resultSoFar - prevNum + prevNum * value, prevNum * value,
                      i + 1);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        addOp(num, "", target, 0, 0, 0);

        return answer;
    }
};