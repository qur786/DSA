class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> s1Map, s2Map;
        vector<string> result;

        stringstream ss1(s1);
        string word1;

        while (ss1 >> word1) {
            s1Map[word1]++;
        }

        stringstream ss2(s2);
        string word2;

        while (ss2 >> word2) {
            s2Map[word2]++;
        }

        for (const auto& [word, count] : s1Map) {
            if (count > 1)
                continue;
            if (!s2Map.count(word))
                result.push_back(word);
        }
        for (const auto& [word, count] : s2Map) {
            if (count > 1)
                continue;
            if (!s1Map.count(word))
                result.push_back(word);
        }

        return result;
    }
};