class Solution {
public:
    long long eval(long long left, long long right, char op) {
        if (op == '+')
            return left + right;
        if (op == '-')
            return left - right;

        return 0;
    }
    int calculate(string s) {
        stack<long long> nums;
        stack<char> ops;
        int size = s.size();
        char last_char = ' ';

        for (int i = 0; i < size; i++) {
            if (isspace(s[i]))
                continue;
            else if (s[i] >= '0' && s[i] <= '9') {
                string n;
                while (i < size && s[i] >= '0' && s[i] <= '9') {
                    n.push_back(s[i]);
                    i++;
                }
                nums.push(stoll(n));
                i--;
            } else if (s[i] == '(')
                ops.push(s[i]);
            else if (s[i] == ')') {
                while (ops.top() != '(') {
                    long long right = nums.top();
                    nums.pop();
                    long long left = nums.top();
                    nums.pop();

                    long long result = eval(left, right, ops.top());
                    nums.push(result);
                    ops.pop();
                }
                ops.pop();
            } else {
                if (last_char == ' ' || last_char == '(')
                    nums.push(0);
                if (!ops.empty() && ops.top() != '(') {
                    long long right = nums.top();
                    nums.pop();
                    long long left = nums.top();
                    nums.pop();

                    long long result = eval(left, right, ops.top());
                    nums.push(result);
                    ops.pop();
                }
                ops.push(s[i]);
            }

            last_char = s[i];
        }

        while (!ops.empty()) {
            long long right = nums.top();
            nums.pop();
            long long left = nums.top();
            nums.pop();

            long long result = eval(left, right, ops.top());
            nums.push(result);
            ops.pop();
        }

        return nums.top();
    }
};