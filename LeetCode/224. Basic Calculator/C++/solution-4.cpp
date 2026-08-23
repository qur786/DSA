class Solution {
private:
    long long eval(long long left, long long right, char op) {
        if (op == '-')
            return left - right;
        if (op == '+')
            return left + right;

        return 0;
    }
    void evaluate(stack<long long>& values, stack<char>& ops) {
        long long right = values.top();
        values.pop();
        long long left = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();

        values.push(eval(left, right, op));
    }

public:
    int calculate(string s) {
        char last_char = ' ';
        stack<long long> values;
        stack<char> ops;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            if (isspace(s[i]))
                continue;
            else if (s[i] == '(')
                ops.push(s[i]);
            else if (isdigit(s[i])) {
                long long num = 0;
                while (i < size && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                values.push(num);
                i = i - 1;
            } else if (s[i] == ')') {
                while (ops.top() != '(')
                    evaluate(values, ops);
                ops.pop();
            } else {
                if (last_char == ' ' || last_char == '(') {
                    values.push(0);
                }
                if (!ops.empty() && ops.top() != '(')
                    evaluate(values, ops);
                ops.push(s[i]);
            }
            last_char = s[i];
        }

        while (values.size() > 1) {
            evaluate(values, ops);
        }

        return values.top();
    }
};