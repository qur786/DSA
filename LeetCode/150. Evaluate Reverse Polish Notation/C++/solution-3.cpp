class Solution {
private:
    int evaluate(int left, int right, const string& op) {
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
    unordered_set<string> operators = {"+", "/", "-", "*"};

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        for (const string& token : tokens) {
            if (operators.count(token)) {
                int right = nums.top();
                nums.pop();
                int left = nums.top();
                nums.pop();
                nums.push(this->evaluate(left, right, token));
            } else
                nums.push(stoi(token));
        }

        return nums.top();
    }
};