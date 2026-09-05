class Solution {
public:
    vector<int> diStringMatch(string s) {
        int size = s.size();
        int left = 0, right = size;
        vector<int> answer;
        answer.reserve(size);
        for (char ch : s)
            answer.push_back(ch == 'I' ? left++ : right--);

        answer.push_back(left);

        return answer;
    }
};