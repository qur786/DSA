class Solution {
private:
    void evaluate(stack<char>& ops, stack<long long>& values) {
        char op = ops.top();
        ops.pop();
        long long right = values.top();
        values.pop();
        long long left = values.top();
        values.pop();

        if (op == '+')
            values.push(left + right);
        else
            values.push(left - right);
    }

public:
    int calculate(string s) {
        stack<char> ops;
        stack<long long> values;
        long long num = 0;
        int size = s.size();
        char last_char = '#';

        for (int i = 0; i < size; i++) {
            if (isspace(s[i]))
                continue;
            else if (isdigit(s[i])) {
                while (i < size && isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                    i += 1;
                }
                i -= 1;
                values.push(num);
                num = 0;
            } else if (s[i] == '(')
                ops.push(s[i]);
            else if (s[i] == ')') {
                while (ops.top() != '(') {
                    evaluate(ops, values);
                }
                ops.pop();
            } else {
                if (last_char == '(' || last_char == '#')
                    values.push(num);
                while (!ops.empty() && ops.top() != '(') {
                    evaluate(ops, values);
                }
                ops.push(s[i]);
            }

            last_char = s[i];
        }

        while (!ops.empty()) {
            evaluate(ops, values);
        }

        return values.top();
    }
};