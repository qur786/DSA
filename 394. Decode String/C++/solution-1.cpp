class Solution {
public:
    string stringMultiplication(const string& s, int count) {
        string result;
        result.reserve(s.size() * count);
        for (int i = 0; i < count; i++) {
            result.append(s);
        }

        return result;
    }
    string decodeString(string s) {
        vector<string> strStack;
        vector<int> numStack;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            if (s[i] == '[')
                strStack.push_back("[");
            else if (isdigit(s[i])) {
                int num = 0;
                while (isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                numStack.push_back(num);
                i--;
            } else if (isalpha(s[i])) {
                string str;
                while (isalpha(s[i])) {
                    str.push_back(s[i]);
                    i++;
                }
                strStack.push_back(str);
                i--;
            } else {
                string str;
                while (strStack.back() != "[") {
                    str = strStack.back() + str;
                    strStack.pop_back();
                }

                strStack.pop_back(); // Removing [
                int count = numStack.back();
                numStack.pop_back();
                string pattern = stringMultiplication(str, count);

                strStack.push_back(pattern);
            }
        }

        string result;

        for (const string& s : strStack)
            result.append(s);
        return result;
    }
};