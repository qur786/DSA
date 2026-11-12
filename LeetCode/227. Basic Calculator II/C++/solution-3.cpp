class Solution {
private:
    unordered_map<char, int> prec = {
        {'/', 2},
        {'*', 2},
        {'+', 1},
        {'-', 1},
    };
    void evaluate(stack<long long>& nums, stack<char>& ops) {
        char op = ops.top();
        ops.pop();
        long long right = nums.top();
        nums.pop();
        long long left = nums.top();
        nums.pop();

        if (op == '/')
            nums.push(left / right);
        else if (op == '*')
            nums.push(left * right);
        else if (op == '+')
            nums.push(left + right);
        else
            nums.push(left - right);
    }

public:
    int calculate(string s) {
        long long num = 0;
        int size = s.size();
        stack<long long> nums;
        stack<char> ops;

        for (int i = 0; i < size; i++) {
            if (isspace(s[i]))
                continue;
            else if (isdigit(s[i])) {
                while (i < size && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                nums.push(num);
                num = 0;
                i -= 1;
            } else {
                while (!ops.empty() && prec[ops.top()] >= prec[s[i]]) {
                    evaluate(nums, ops);
                }
                ops.push(s[i]);
            }
        }

        while (!ops.empty()) {
            evaluate(nums, ops);
        }

        return nums.top();
    }
};