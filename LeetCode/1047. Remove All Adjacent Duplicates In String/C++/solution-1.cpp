class Solution {
public:
    string removeDuplicates(string s) {
        string answer;
        answer.reserve(s.size());

        for (char& c : s) {
            if (answer.empty() || answer.back() != c) {
                answer.push_back(c);
                continue;
            }
            while (!answer.empty() && answer.back() == c)
                answer.pop_back();
        }

        return answer;
    }
};