class Solution {
public:
    string removeDuplicateLetters(string s) {
        int size = s.size();
        string answer;
        answer.reserve(size);
        unordered_map<char, int> charCount;
        unordered_map<char, bool> added;
        charCount.reserve(26);

        for (char c : s)
            charCount[c]++;

        for (int i = 0; i < size; i++) {
            charCount[s[i]]--;
            if (!added[s[i]]) {
                while (!answer.empty() && charCount[answer.back()] > 0 &&
                       answer.back() > s[i]) {
                    added[answer.back()] = false;
                    answer.pop_back();
                }
                answer.push_back(s[i]);
                added[s[i]] = true;
            }
        }

        return answer;
    }
};