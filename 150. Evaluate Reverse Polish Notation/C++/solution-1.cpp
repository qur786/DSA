class Solution {
public:
    bool isOperator(const string& s) {
        if (s == "+" || s == "-" || s == "/" || s == "*")
            return true;

        return false;
    }
    int evaluate(const int& left, const int& right, const string& op) {
        int result;
        if (op == "+")
            result = left + right;
        else if (op == "-")
            result = left - right;
        else if (op == "/")
            result = left / right;
        else if (op == "*")
            result = left * right;

        return result;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result;

        for (const string& token : tokens) {
            if (isOperator(token)) {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                int val = evaluate(left, right, token);
                st.push(val);
            } else
                st.push(stoi(token));
        }

        return st.top();
    }
};