class Solution {
private:
    int eval(int left, int right, char op) {
        if (op == '+')
            return left + right;
        if (op == '-')
            return left - right;
        if (op == '*')
            return left * right;
        if (op == '/')
            return left / right;

        return 0;
    }
    unordered_map<char, int> preced = {
        {'/', 1},
        {'*', 1},
        {'+', 0},
        {'-', 0},
    };

public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        int size = s.size();

        int num = 0;

        for (int i = 0; i < size; i++) {
            if (isspace(s[i]))
                continue;
            else if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else {
                nums.push(num);
                num = 0;
                while (!ops.empty() && preced[ops.top()] >= preced[s[i]]) {
                    int right = nums.top();
                    nums.pop();
                    int left = nums.top();
                    nums.pop();
                    char op = ops.top();
                    ops.pop();
                    nums.push(eval(left, right, op));
                }
                ops.push(s[i]);
            }
        }
        nums.push(num);
        while (!ops.empty()) {
            int right = nums.top();
            nums.pop();
            int left = nums.top();
            nums.pop();
            char op = ops.top();
            ops.pop();
            nums.push(eval(left, right, op));
        }

        return nums.top();
    }
};