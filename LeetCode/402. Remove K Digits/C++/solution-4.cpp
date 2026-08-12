class Solution {
public:
    string removeKdigits(string num, int k) {
        int size = num.size();
        if (size <= k)
            return "0";

        string smallestNumber;

        for (int i = 0; i < size; i++) {
            while (!smallestNumber.empty() && k > 0 &&
                   smallestNumber.back() > num[i]) {
                smallestNumber.pop_back();
                k--;
            }

            smallestNumber.push_back(num[i]);
        }

        if (smallestNumber.empty())
            return "0";

        if (k > 0)
            smallestNumber.resize(smallestNumber.size() - k);

        size_t pos = smallestNumber.find_first_not_of('0');
        if (pos == string::npos)
            return "0";
        else
            smallestNumber.erase(smallestNumber.begin(),
                                 smallestNumber.begin() + pos);

        return smallestNumber.empty() ? "0" : smallestNumber;
    }
};