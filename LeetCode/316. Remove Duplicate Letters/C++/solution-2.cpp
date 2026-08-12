class Solution {
public:
    string removeDuplicateLetters(string s) {
        int size = s.size();
        string result;
        array<int, 26> charCount{}, seen{};

        for (char c : s)
            charCount[c - 'a']++;

        for (int i = 0; i < size; i++) {
            charCount[s[i] - 'a']--;
            if (seen[s[i] - 'a'])
                continue;
            while (!result.empty() && result.back() > s[i] &&
                   charCount[result.back() - 'a'] > 0) {
                seen[result.back() - 'a'] = 0;
                result.pop_back();
            }

            result.push_back(s[i]);
            seen[s[i] - 'a'] = 1;
        }

        return result;
    }
};