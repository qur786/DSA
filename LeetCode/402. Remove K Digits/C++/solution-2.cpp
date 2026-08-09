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

        answer.resize(answer.size() - k);

        size_t nonZeroFirstIndex = answer.find_first_not_of('0');
        if (nonZeroFirstIndex == string::npos)
            return "0";
        answer.erase(answer.begin(), answer.begin() + nonZeroFirstIndex);

        return answer.empty() ? "0" : answer;
    }
};