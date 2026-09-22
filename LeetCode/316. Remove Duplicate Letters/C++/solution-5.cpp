class Solution {
public:
    string removeDuplicateLetters(string s) {
        int size = s.size();
        vector<bool> visited(26, false);
        unordered_map<char, int> charMap;
        string answer;

        for (char c : s)
            charMap[c]++;

        for (int i = 0; i < size; i++) {
            charMap[s[i]]--;
            if (visited[s[i] - 'a'])
                continue;
            while (!answer.empty() && answer.back() > s[i] &&
                   charMap[answer.back()] > 0) {
                visited[answer.back() - 'a'] = false;
                answer.pop_back();
            }
            visited[s[i] - 'a'] = true;
            answer.push_back(s[i]);
        }

        return answer;
    }
};