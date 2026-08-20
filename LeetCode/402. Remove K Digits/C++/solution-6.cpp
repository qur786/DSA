class Solution {
public:
    string removeKdigits(string num, int k) {
        int size = num.size();
        if (size == k)
            return "0";
        string newNum;
        newNum.reserve(size);

        for (int i = 0; i < size; i++) {
            while (k > 0 && !newNum.empty() && (newNum.back() > num[i])) {
                newNum.pop_back();
                k--;
            }
            newNum.push_back(num[i]);
        }

        if (k > 0)
            newNum.resize(newNum.size() - k);

        size_t pos = newNum.find_first_not_of('0');

        if (pos == string::npos)
            return "0";

        newNum.erase(0, pos);

        return newNum;
    }
};