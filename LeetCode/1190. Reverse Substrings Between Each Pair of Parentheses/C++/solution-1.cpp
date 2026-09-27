class Solution {
public:
    string reverseParentheses(string s) {
        int size = s.size();
        deque<string> dq;
        string curr;

        for (int i = 0; i < size; i++) {
            if (s[i] == '(') {
                dq.push_back(curr);
                dq.push_back("(");
                curr = "";
            } else if (s[i] == ')') {
                string str = curr;
                while (!dq.empty() && dq.back() != "(") {
                    str = dq.back() + str;
                    dq.pop_back();
                }
                if (!dq.empty())
                    dq.pop_back();
                reverse(str.begin(), str.end());
                dq.push_back(str);
                curr = "";
            } else {
                curr.push_back(s[i]);
            }
        }

        string ans;

        while (!dq.empty()) {
            ans.append(dq.front());
            dq.pop_front();
        }

        ans.append(curr);

        return ans;
    }
};