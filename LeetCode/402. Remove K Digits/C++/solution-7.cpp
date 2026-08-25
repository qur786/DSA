class Solution {
public:
    string removeKdigits(string num, int k) {
        int size = num.size();
        string result;
        result.reserve(size);

        for (int i = 0; i < size; i++) {
            while (k > 0 && !result.empty() && (result.back() > num[i])) {
                result.pop_back();
                k--;
            }
            result.push_back(num[i]);
        }

        if (k)
            result.resize(result.size() - k);

        size_t pos = result.find_first_not_of('0');

        if (pos == string::npos)
            return "0";

        return result.substr(pos);
    }
};