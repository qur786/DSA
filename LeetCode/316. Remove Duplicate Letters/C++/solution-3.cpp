class Solution {
public:
    string removeDuplicateLetters(string s) {
        int size = s.size();
        array<int, 26> charCount{};
        array<bool, 26> visited{};
        for (char c : s)
            charCount[c - 'a']++;
        string result;
        result.reserve(size);

        for (int i = 0; i < size; i++) {
            charCount[s[i] - 'a']--;

            if (visited[s[i] - 'a'])
                continue;

            while (!result.empty() && charCount[result.back() - 'a'] > 0 &&
                   result.back() > s[i]) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(s[i]);
            visited[s[i] - 'a'] = true;
        }

        return result;
    }
};