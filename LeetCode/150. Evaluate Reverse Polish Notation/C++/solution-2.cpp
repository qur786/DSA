class Solution {
public:
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
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> operators = {
            "/",
            "*",
            "+",
            "-",
        };
        stack<int> result;
        for (const string& token : tokens) {
            if (operators.count(token)) {
                int right = result.top();
                result.pop();
                int left = result.top();
                result.pop();
                int ans = eval(left, right, token);
                result.push(ans);
            } else {
                result.push(stoi(token));
            }
        }

        return result.top();
    }
};