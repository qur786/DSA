class Solution {
private:
    vector<string> answer;
    unordered_map<char, int> preced = {
        {'*', 1},
        {'+', 0},
        {'-', 0},
    };
    string operators = "+-*";
    long long eval(long long left, long long right, char op) {
        if (op == '+')
            return left + right;
        if (op == '-')
            return left - right;
        return left * right;
    }
    long long evaluate(string exp) {
        stack<long long> nums;
        stack<char> ops;
        int size = exp.size();
        string currentNum = "";
        for (int i = 0; i < size; i++) {
            if (isdigit(exp[i])) {
                currentNum.push_back(exp[i]);
            } else {
                if (currentNum.size() > 1 && currentNum[0] == '0')
                    return LLONG_MIN;
                nums.push(stoll(currentNum));
                currentNum = "";
                while (!ops.empty() && preced[ops.top()] >= preced[exp[i]]) {
                    long long right = nums.top();
                    nums.pop();
                    long long left = nums.top();
                    nums.pop();
                    nums.push(eval(left, right, ops.top()));
                    ops.pop();
                }
                ops.push(exp[i]);
            }
        }
        if (currentNum.size() > 1 && currentNum[0] == '0')
            return LLONG_MIN;

        nums.push(stoll(currentNum));
        while (!ops.empty()) {
            long long right = nums.top();
            nums.pop();
            long long left = nums.top();
            nums.pop();
            nums.push(eval(left, right, ops.top()));
            ops.pop();
        }
        return nums.top();
    }
    void genExp(string& num, string& comb, int target, int size, int index,
                bool canAddOperator) {
        if (index >= size) {
            long long value = evaluate(comb);
            if (value != LLONG_MIN && value == target)
                answer.push_back(comb);
            return;
        }

        comb.push_back(num[index]);
        genExp(num, comb, target, size, index + 1, true);
        comb.pop_back();

        if (canAddOperator) {
            for (char c : operators) {
                comb.push_back(c);
                genExp(num, comb, target, size, index, false);
                comb.pop_back();
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        string comb;
        int size = num.size();
        genExp(num, comb, target, size, 0, false);
        return answer;
    }
};