class Solution {
public:
    string multiplyString(const string& s, int count) {
        string result;

        for (int i = 0; i < count; i++)
            result.append(s);

        return result;
    }
    string decodeString(string s) {
        vector<int> nums;
        vector<string> str;
        string result;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            if (s[i] == '[')
                str.push_back("[");
            else if (isdigit(s[i])) {
                int currentNum = 0;
                while (isdigit(s[i])) {
                    currentNum = currentNum * 10 + (s[i] - '0');
                    i++;
                }
                nums.push_back(currentNum);
                i = i - 1;
            } else if (isalpha(s[i])) {
                string currentStr;
                while (isalpha(s[i])) {
                    currentStr.push_back(s[i]);
                    i++;
                }
                str.push_back(currentStr);
                i = i - 1;
            } else {
                int n = nums.back();
                nums.pop_back();
                string s;
                while (!str.empty() && str.back() != "[") {
                    s = str.back() + s;
                    str.pop_back();
                }
                str.pop_back();
                string pattern = multiplyString(s, n);
                str.push_back(pattern);
            }
        }

        for (int i = 0; i < str.size(); i++)
            result.append(str[i]);

        return result;
    }
};