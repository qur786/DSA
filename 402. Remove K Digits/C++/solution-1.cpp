class Solution {
public:
    string removeKdigits(string num, int k) {
        int size = num.size();

        for (int curr = 0; curr < k; curr++) {
            for (int i = 0; i < size; i++) {
                if (num[i] == '#')
                    continue;
                int skip = 1;
                while ((i + skip < size) && num[i + skip] == '#')
                    skip++;
                if (i + skip >= size || num[i] > num[i + skip]) {
                    num[i] = '#';
                    break;
                }
            }
        }

        string answer;
        answer.reserve(size - k + 1);

        for (int i = 0; i < size; i++)
            if (num[i] != '#')
                answer.push_back(num[i]);

        size_t nonZeroFirstPosition = answer.find_first_not_of('0');
        answer.erase(answer.begin(),
                     nonZeroFirstPosition == string::npos
                         ? answer.end()
                         : answer.begin() + nonZeroFirstPosition);

        return answer.size() == 0 ? "0" : answer;
    }
};