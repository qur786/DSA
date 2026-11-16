class Solution {
private:
    string multiply(const string& s, int count) {
        string result;

        for (int i = 0; i < count; i++)
            result.append(s);

        return result;
    }
    void evaluate(vector<string>& chars, vector<int>& nums) {
        string word;
        while (chars.back() != "[") {
            word = chars.back() + word;
            chars.pop_back();
        }
        chars.pop_back();
        int count = nums.back();
        nums.pop_back();
        chars.push_back(multiply(word, count));
    }

public:
    string decodeString(string s) {
        vector<string> chars;
        vector<int> nums;
        int num = 0;
        string str;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            if (isdigit(s[i])) {
                while (i < size && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i -= 1;
                nums.push_back(num);
                num = 0;
            } else if (isalpha(s[i])) {
                while (i < size && isalpha(s[i])) {
                    str.push_back(s[i]);
                    i++;
                }
                i -= 1;
                chars.push_back(move(str));
            } else if (s[i] == '[')
                chars.push_back("[");
            else {
                evaluate(chars, nums);
            }
        }

        string result;

        for (string word : chars) {
            result.append(move(word));
        }

        return result;
    }
};