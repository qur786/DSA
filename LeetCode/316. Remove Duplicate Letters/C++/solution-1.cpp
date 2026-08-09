class Solution {
public:
    string removeDuplicateLetters(string s) {
        string smallestUniqueString;
        int size = s.size();
        array<int, 26> charCount{};
        array<bool, 26> visited{};

        for (char c : s)
            charCount[c - 'a']++;

        for (int i = 0; i < size; i++) {
            charCount[s[i] - 'a']--;
            if (visited[s[i] - 'a'])
                continue;
            while (!smallestUniqueString.empty() &&
                   smallestUniqueString.back() > s[i] &&
                   charCount[smallestUniqueString.back() - 'a'] > 0) {
                visited[smallestUniqueString.back() - 'a'] = false;
                smallestUniqueString.pop_back();
            }

            smallestUniqueString.push_back(s[i]);
            visited[s[i] - 'a'] = true;
        }

        return smallestUniqueString;
    }
};