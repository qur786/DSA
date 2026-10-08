class Solution {
private:
    long long eval(long long left, long long right, char op) {
        if (op == '+')
            return left + right;
        return left - right;
    }
    void evaluate(stack<char>& ops, stack<long long>& nums) {
        long long right = nums.top();
        nums.pop();
        long long left = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        nums.push(eval(left, right, op));
    }

public:
    int calculate(string s) {
        int size = s.size();
        stack<long long> nums;
        stack<char> ops;
        string num;
        char prevChar = '#';

        for (int i = 0; i < size; i++) {
            if (isspace(s[i]))
                continue;
            else if (isdigit(s[i]))
                num.push_back(s[i]);
            else if (s[i] == '(') {
                if (!num.empty()) {
                    nums.push(stoll(num));
                    num = "";
                }
                ops.push(s[i]);
            } else if (s[i] == ')') {
                if (!num.empty()) {
                    nums.push(stoll(num));
                    num = "";
                }
                while (ops.top() != '(') {
                    evaluate(ops, nums);
                }
                ops.pop();
            } else {
                if (!num.empty()) {
                    nums.push(stoll(num));
                    num = "";
                } else if (prevChar == '#' || prevChar == '(')
                    nums.push(0);

                if (!ops.empty() && ops.top() != '(') {
                    evaluate(ops, nums);
                }
                ops.push(s[i]);
            }
            prevChar = s[i];
        }

        if (!num.empty()) {
            nums.push(stoll(num));
            num = "";
        }

        while (!ops.empty()) {
            evaluate(ops, nums);
        }

        return nums.top();
    }
};