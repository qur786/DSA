class Solution {
private:
    string multiply(string& s, int count) {
        string result;
        for (int i = 0; i < count; i++) {
            result.append(s);
        }

        return result;
    }
    void evaluate(vector<string>& strs, stack<int>& nums) {
        int count = nums.top();
        nums.pop();
        string s;
        while (strs.back() != "[") {
            s = strs.back() + s;
            strs.pop_back();
        }
        strs.pop_back();
        strs.push_back(multiply(s, count));
    }

public:
    string decodeString(string s) {
        stack<int> nums;
        vector<string> strs;
        string num, str;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            if (isdigit(s[i])) {
                num.push_back(s[i]);
            } else if (s[i] == '[') {
                if (!num.empty()) {
                    nums.push(stoi(num));
                    num = "";
                }
                if (!str.empty()) {
                    strs.push_back(str);
                    str = "";
                }
                strs.push_back("[");
            } else if (s[i] == ']') {
                if (!str.empty()) {
                    strs.push_back(str);
                    str = "";
                }
                evaluate(strs, nums);
            } else {
                str.push_back(s[i]);
            }
        }
        if (!str.empty()) {
            strs.push_back(str);
            str = "";
        }

        string result;

        for (int i = 0; i < strs.size(); i++)
            result.append(strs[i]);

        return result;
    }
};