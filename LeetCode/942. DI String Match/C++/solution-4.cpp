class Solution {
public:
    vector<int> diStringMatch(string s) {
        int size = s.size();
        int iCount = 0, dCount = size;
        vector<int> answer;
        answer.reserve(size + 1);
        for (char c : s) {
            if (c == 'I')
                answer.push_back(iCount++);
            else
                answer.push_back(dCount--);
        }
        answer.push_back(iCount);

        return answer;
    }
};