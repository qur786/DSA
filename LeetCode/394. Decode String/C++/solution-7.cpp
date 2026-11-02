class Solution {
private:
    string multiply(const string& str, int count) {
        string s;

        for (int i = 0; i < count; i++)
            s.append(str);

        return s;
    }
    void evaluate(vector<string>& strs, vector<int>& nums) {
        string str;
        int count = nums.back();
        nums.pop_back();
        while (strs.back() != "[") {
            str = strs.back() + str;
            strs.pop_back();
        }
        strs.pop_back();
        strs.push_back(multiply(str, count));
    }

public:
    string decodeString(string s) {
        int size = s.size();
        vector<string> strs;
        vector<int> nums;
        int num = 0;
        string str;

        for (int i = 0; i < size; i++) {
            if (isdigit(s[i])) {
                while (i < size && isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                nums.push_back(num);
                i -= 1;
                num = 0;
            } else if (isalpha(s[i])) {
                while (i < size && isalpha(s[i])) {
                    str.push_back(s[i]);
                    i++;
                }
                strs.push_back(str);
                i -= 1;
                str.clear();
            } else if (s[i] == '[')
                strs.push_back("[");
            else {
                evaluate(strs, nums);
            }
        }

        string result;

        for (int i = 0; i < strs.size(); i++)
            result.append(strs[i]);

        return result;
    }
};