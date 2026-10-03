class Solution {
private:
    vector<string> answer;
    void addOp(string& num, const string& comb, long long runningSum,
               long long prevNum, int target, int index, int size) {
        if (index == size) {
            if (runningSum == target) {
                answer.push_back(comb);
            }
            return;
        }

        string numStr;
        long long value = 0;

        for (int i = index; i < size; i++) {
            if (i > index && num[index] == '0')
                return;
            numStr.push_back(num[i]);
            value = value * 10 + (num[i] - '0');
            if (index == 0)
                addOp(num, comb + numStr, value, value, target, i + 1, size);
            else {
                addOp(num, comb + "+" + numStr, runningSum + value, value,
                      target, i + 1, size);
                addOp(num, comb + "-" + numStr, runningSum - value, -value,
                      target, i + 1, size);
                addOp(num, comb + "*" + numStr,
                      runningSum - prevNum + prevNum * value, prevNum * value,
                      target, i + 1, size);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        addOp(num, "", 0, 0, target, 0, num.size());

        return answer;
    }
};