class Solution {
private:
    unordered_set<string> op = {"+", "/", "-", "*"};
    int eval(int left, int right, const string& op) {
        if (op == "/")
            return left / right;
        if (op == "*")
            return left * right;
        if (op == "+")
            return left + right;
        if (op == "-")
            return left - right;

        return 0;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> values;

        for (const string& str : tokens) {
            if (op.count(str)) {
                int right = values.top();
                values.pop();
                int left = values.top();
                values.pop();
                values.push(eval(left, right, str));
            } else {
                int num = stoi(str);
                values.push(num);
            }
        }

        return values.top();
    }
};