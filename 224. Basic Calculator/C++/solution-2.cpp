class Solution {
public:
    long long eval(long long left, long long right, char op) {
        if (op == '+')
            return left + right;
        if (op == '-')
            return left - right;

        return 0;
    }
    void evaluate(stack<long long>& result, stack<char>& opStack) {
        long long right = result.top();
        result.pop();
        long long left = result.top();
        result.pop();
        result.push(eval(left, right, opStack.top()));
        opStack.pop();
    }
    int calculate(string s) {
        stack<long long> result;
        stack<char> opStack;
        char last_char = ' ';
        int size = s.size();

        for (int i = 0; i < size; i++) {
            char c = s[i];
            if (isspace(c))
                continue;
            if (c == '(') {
                opStack.push(c);
            } else if (c == ')') {
                while (opStack.top() != '(') {
                    evaluate(result, opStack);
                }
                opStack.pop();
            } else if (c >= '0' && c <= '9') {
                string num;
                while (i < size && s[i] >= '0' && s[i] <= '9') {
                    num.push_back(s[i]);
                    i++;
                }
                i--;
                result.push(stoll(num));
            } else {
                if (last_char == '(' || last_char == ' ')
                    result.push(0);
                if (!opStack.empty() && opStack.top() != '(') {
                    evaluate(result, opStack);
                }
                opStack.push(c);
            }
            last_char = s[i];
        }

        while (!opStack.empty()) {
            evaluate(result, opStack);
        }

        return result.top();
    }
};