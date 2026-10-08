class Solution {
private:
    unordered_map<char, int> rank = {
        {'*', 2},
        {'/', 2},
        {'+', 1},
        {'-', 1},
    };
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
    void evaluate(stack<long long>& nums, stack<char>& ops) {
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
        string str, num;

        for (int i = 0; i < size; i++) {
            if (isspace(s[i]))
                continue;
            else if (isdigit(s[i])) {
                num.push_back(s[i]);
            } else {
                if (!num.empty()) {
                    nums.push(stoll(num));
                    num = "";
                }

                while (!ops.empty() && rank[ops.top()] >= rank[s[i]]) {
                    evaluate(nums, ops);
                }
                ops.push(s[i]);
            }
        }

        if (!num.empty()) {
            nums.push(stoll(num));
            num = "";
        }

        while (!ops.empty()) {
            evaluate(nums, ops);
        }
        return nums.top();
    }
};