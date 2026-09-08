class Solution {
public:
    string removeDuplicates(string s) {
        string answer;
        int size = s.size();
        answer.reserve(size);

        for (int i = 0; i < size; i++) {
            if (answer.empty() || answer.back() != s[i])
                answer.push_back(s[i]);
            else
                answer.pop_back();
        }

        return answer;
    }
};