class Solution {
private:
    void evaluate(stack<long long>& nums, stack<char>& ops) {
        char op = ops.top();
        ops.pop();
        long long right = nums.top();
        nums.pop();
        long long left = nums.top();
        nums.pop();

        if (op == '+')
            nums.push(left + right);
        if (op == '-')
            nums.push(left - right);
    }

public:
    int calculate(string s) {
        stack<long long> nums;
        stack<char> ops;
        long long num = 0;
        int size = s.size();
        char last_char = '#';

        for (int i = 0; i < size; i++) {
            if (isspace(s[i]))
                continue;
            else if (isdigit(s[i])) {
                while (i < size && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i += 1;
                }
                i -= 1;
                nums.push(num);
                num = 0;
            } else if (s[i] == '(') {
                ops.push(s[i]);
            } else if (s[i] == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    evaluate(nums, ops);
                }
                ops.pop();
            } else {
                if (last_char == '#' || last_char == '(')
                    nums.push(0LL);
                while (!ops.empty() && ops.top() != '(') {
                    evaluate(nums, ops);
                }
                ops.push(s[i]);
            }

            last_char = s[i];
        }

        while (!ops.empty()) {
            evaluate(nums, ops);
        }

        return nums.top();
    }
};