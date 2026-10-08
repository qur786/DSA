class Solution {
private:
    string multiply(string& s, int count) {
        string result;
        result.reserve(s.size() * count);
        for (int i = 0; i < count; i++) {
            result.append(s);
        }

        return result;
    }
    void evaluate(vector<string>& strs, vector<int>& nums) {
        int count = nums.back();
        nums.pop_back();
        string s;
        while (!strs.empty() && strs.back() != "[") {
            s = strs.back() + s;
            strs.pop_back();
        }
        strs.pop_back();

        strs.push_back(multiply(s, count));
    }

public:
    string decodeString(string s) {
        string result;
        int size = s.size();
        vector<string> strs;
        vector<int> nums;
        string str, num;

        for (int i = 0; i < size; i++) {
            if (isdigit(s[i])) {
                num.push_back(s[i]);
            } else if (isalpha(s[i])) {
                str.push_back(s[i]);
            } else if (s[i] == '[') {
                if (!num.empty()) {
                    nums.push_back(stoi(num));
                    num = "";
                }
                if (!str.empty()) {
                    strs.push_back(str);
                    str = "";
                }
                strs.push_back("[");
            } else {
                if (!num.empty()) {
                    nums.push_back(stoi(num));
                    num = "";
                }
                if (!str.empty()) {
                    strs.push_back(str);
                    str = "";
                }
                evaluate(strs, nums);
            }
        }
        if (!str.empty()) {
            strs.push_back(str);
            str = "";
        }

        for (int i = 0; i < strs.size(); i++) {
            result.append(strs[i]);
        }

        return result;
    }
};