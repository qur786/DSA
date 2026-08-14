class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> result;
        unordered_map<string, int> s1Count, s2Count;

        stringstream ss1(s1), ss2(s2);
        string word;
        while (ss1 >> word)
            s1Count[word]++;
        while (ss2 >> word)
            s2Count[word]++;

        for (const auto& [word, count] : s1Count)
            if (count == 1 && !s2Count.count(word))
                result.push_back(word);
        for (const auto& [word, count] : s2Count)
            if (count == 1 && !s1Count.count(word))
                result.push_back(word);

        return result;
    }
};