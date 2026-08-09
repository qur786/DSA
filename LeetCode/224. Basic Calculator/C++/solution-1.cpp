class Solution {
public:
    unordered_set<char> opset = {'+', '-'};
    long long eval(long long left, long long right, char ops) {
        if (ops == '+')
            return left + right;
        if (ops == '-')
            return left - right;
        return 0;
    }
    void evalutate(stack<long long>& nums, stack<char>& ops) {
        long long right = nums.top();
        nums.pop();
        long long left = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        long long res = eval(left, right, op);
        nums.push(res);
    }
    int calculate(string s) {
        stack<long long> nums;
        stack<char> ops;
        int size = s.size();
        char last_char = ' ';
        for (int i = 0; i < size; i++) {
            if (isspace(s[i]))
                continue;
            if (s[i] == '(') {
                ops.push(s[i]);
                last_char = s[i];
            } else if (s[i] == ')') {
                while (ops.top() != '(') {
                    evalutate(nums, ops);
                }
                ops.pop();
            } else if (opset.count(s[i])) {
                if (last_char < '0' || last_char > '9')
                    nums.push(0);
                while (!ops.empty() && opset.count(ops.top())) {
                    evalutate(nums, ops);
                }
                ops.push(s[i]);
                last_char = s[i];
            } else {
                string num;
                while (i < size && s[i] >= '0' && s[i] <= '9') {
                    num.push_back(s[i]);
                    i++;
                }
                i--;
                last_char = s[i];
                nums.push(stoll(num));
            }
        }

        while (!ops.empty() && nums.size() >= 2) {
            evalutate(nums, ops);
        }

        return nums.top();
    }
};