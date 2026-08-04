class Solution {
public:
    string removeKdigits(string num, int k) {
        string monotonicIncreasingNum;
        int size = num.size();

        for (int i = 0; i < size; i++) {
            while (k > 0 && !monotonicIncreasingNum.empty() &&
                   monotonicIncreasingNum.back() > num[i]) {
                monotonicIncreasingNum.pop_back();
                k--;
            }
            monotonicIncreasingNum.push_back(num[i]);
        }

        if (k > 0)
            monotonicIncreasingNum.resize(monotonicIncreasingNum.size() - k);

        size_t pos = monotonicIncreasingNum.find_first_not_of('0');

        if (pos != string::npos)
            monotonicIncreasingNum.erase(0, pos);
        else
            return "0";

        return monotonicIncreasingNum;
    }
};