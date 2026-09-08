class Solution {
public:
    string removeKdigits(string num, int k) {
        int size = num.size();
        string answer;
        answer.reserve(size);

        for (int i = 0; i < size; i++) {
            while (k > 0 && !answer.empty() && answer.back() > num[i]) {
                answer.pop_back();
                k--;
            }
            answer.push_back(num[i]);
        }

        if (answer.empty())
            return "0";

        if (k > 0)
            answer.resize(answer.size() - k);

        if (answer.empty())
            return "0";

        int pos = answer.find_first_not_of('0');

        if (pos == string::npos)
            return "0";

        return answer.substr(pos);
    }
};