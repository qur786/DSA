class Solution {
private:
    void evaluate(stack<long long>& nums, stack<char>& ops) {
        long long right = nums.top();
        nums.pop();
        long long left = nums.top();
        nums.pop();
        char c = ops.top();
        ops.pop();
        nums.push(eval(left, right, c));
    }
    long long eval(long long left, long long right, char op) {
        if (op == '+')
            return left + right;

        return left - right;
    }

public:
    int calculate(string s) {
        stack<long long> result;
        stack<char> ops;
        int size = s.size();
        char last_char = '#';

        for (int i = 0; i < size; i++) {
            if (isspace(s[i]))
                continue;
            else if (isdigit(s[i])) {
                long long num = 0;
                while (i < size && isdigit(s[i])) {
                    num = num * 10 + (long long)(s[i] - '0');
                    i++;
                }
                result.push(num);
                i = i - 1;
            } else if (s[i] == '(')
                ops.push(s[i]);
            else if (s[i] == ')') {
                while (ops.top() != '(')
                    evaluate(result, ops);
                ops.pop();
            } else {
                if (last_char == '#' || last_char == '(')
                    result.push(0LL);
                if (!ops.empty() && ops.top() != '(')
                    evaluate(result, ops);
                ops.push(s[i]);
            }
            last_char = s[i];
        }

        while (!ops.empty()) {
            evaluate(result, ops);
        }

        return result.top();
    }
};