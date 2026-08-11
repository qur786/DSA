class Solution {
public:
    string removeKdigits(string num, int k) {
        int size = num.size();
        string answer;
        answer.reserve(size);

        for (int i = 0; i < size; i++) {
            while (k > 0 && !answer.empty() && num[i] < answer.back()) {
                answer.pop_back();
                k--;
            }
            answer.push_back(num[i]);
        }

        if (k > 0)
            answer.resize(answer.size() - k);

        size_t notZeroIndex = answer.find_first_not_of('0');
        if (notZeroIndex == string::npos)
            return "0";
        answer.erase(answer.begin(), answer.begin() + notZeroIndex);

        return answer.empty() ? "0" : answer;
    }
};