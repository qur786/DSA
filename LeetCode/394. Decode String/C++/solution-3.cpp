class Solution {
private:
    string multiply(string s, int count) {
        int size = s.size();
        string answer;
        answer.reserve(size * count);

        for (int i = 0; i < count; i++)
            answer.append(s);

        return answer;
    }
    void evaluate(vector<string>& strs, vector<int>& nums) {
        string str;
        while (strs.back() != "[") {
            str = strs.back() + str;
            strs.pop_back();
        }
        strs.pop_back();
        int count = nums.back();
        nums.pop_back();
        strs.push_back(multiply(str, count));
    }

public:
    string decodeString(string s) {
        vector<string> strs;
        vector<int> nums;
        int currentNum = 0;
        string currentStr = "";
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if (s[i] == '[') {
                if (currentNum != 0) {
                    nums.push_back(currentNum);
                    currentNum = 0;
                }
                if (!currentStr.empty()) {
                    strs.push_back(currentStr);
                    currentStr.clear();
                }
                strs.push_back("[");
            } else if (s[i] == ']') {
                if (!currentStr.empty()) {
                    strs.push_back(currentStr);
                    currentStr.clear();
                }
                evaluate(strs, nums);
            } else if (isdigit(s[i])) {
                currentNum = currentNum * 10 + (s[i] - '0');
            } else {
                currentStr.push_back(s[i]);
            }
        }

        string answer;
        for (int i = 0; i < strs.size(); i++)
            answer.append(strs[i]);

        if (!currentStr.empty())
            answer.append(currentStr);

        return answer;
    }
};