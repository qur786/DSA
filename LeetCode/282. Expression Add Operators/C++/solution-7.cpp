class Solution {
private:
    unordered_map<char, int> prec = {
        {'*', 1},
        {'+', 0},
        {'-', 0},
    };
    void eval(stack<long long>& values, stack<char>& chars) {
        char op = chars.top();
        chars.pop();
        long long right = values.top();
        values.pop();
        long long left = values.top();
        values.pop();
        long long res;
        if (op == '*')
            res = left * right;
        else if (op == '+')
            res = left + right;
        else if (op == '-')
            res = left - right;

        values.push(res);
    }
    long long evaluate(const string& expr) {
        int size = expr.size();
        stack<long long> values;
        stack<char> chars;
        string num;

        for (int i = 0; i < size; i++) {
            if (isdigit(expr[i])) {
                num.push_back(expr[i]);
            } else {
                if (!num.empty()) {
                    if (num.size() >= 2 && num[0] == '0')
                        return LLONG_MIN;
                    values.push(stoll(num));
                    num = "";
                }
                while (!chars.empty() && prec[chars.top()] >= prec[expr[i]]) {
                    eval(values, chars);
                }
                chars.push(expr[i]);
            }
        }

        if (!num.empty()) {
            if (num.size() >= 2 && num[0] == '0')
                return LLONG_MIN;

            values.push(stoll(num));
            num = "";
        }
        while (!chars.empty()) {
            eval(values, chars);
        }

        return values.top();
    }
    void solve(string& num, int target, vector<string>& answer,
               const string& comb, int index, bool canAddOp) {
        if (index == num.size()) {
            cout << comb << " ";
            if (evaluate(comb) == target)
                answer.push_back(comb);
            return;
        }

        solve(num, target, answer, comb + num[index], index + 1, true);

        if (canAddOp) {
            solve(num, target, answer, comb + "*" + num[index], index + 1,
                  true);
            solve(num, target, answer, comb + "+" + num[index], index + 1,
                  true);
            solve(num, target, answer, comb + "-" + num[index], index + 1,
                  true);
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> answer;
        solve(num, target, answer, "", 0, false);

        return answer;
    }
};