class Solution {
private:
    void addOp(vector<string>& answer, string& num, const string& comb,
               int size, int target, long long result, long long prevNum,
               int index) {
        if (index == size) {
            if (result == target)
                answer.push_back(comb);
            return;
        }

        string numStr;
        long number = 0;

        for (int j = index; j < size; j++) {
            if (j > index && num[index] == '0')
                break;
            numStr += num[j];
            number = number * 10 + num[j] - '0';

            if (index == 0)
                addOp(answer, num, comb + numStr, size, target, number, number,
                      j + 1);
            else {
                addOp(answer, num, comb + "+" + numStr, size, target,
                      result + number, number, j + 1);
                addOp(answer, num, comb + "-" + numStr, size, target,
                      result - number, -number, j + 1);
                addOp(answer, num, comb + "*" + numStr, size, target,
                      result - prevNum + prevNum * number, prevNum * number,
                      j + 1);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> answer;
        int size = num.size();

        addOp(answer, num, "", size, target, 0, 0, 0);
        return answer;
    }
};