class Solution {
public:
    string removeKdigits(string num, int k) {
        int size = num.size();
        string answer;
        answer.reserve(size);

        for (int i = 0; i < size; i++) {
            while (k > 0 && !answer.empty() && answer.back() > num[i]) {
                k--;
                answer.pop_back();
            }
            answer.push_back(num[i]);
        }

        if (k > 0)
            answer.resize(answer.size() - k);

        auto pos = answer.find_first_not_of('0');

        if (pos == string::npos)
            return "0";

        answer.erase(0, pos);

        if (answer.empty())
            return "0";

        return answer;
    }
};