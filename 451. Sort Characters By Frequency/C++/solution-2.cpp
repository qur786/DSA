class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> charCount;
        string result;
        int size = s.size(), maxCount = 0;
        result.reserve(size);

        for (char c : s) {
            charCount[c]++;
            maxCount = max(maxCount, charCount[c]);
        }

        vector<vector<char>> buckets(maxCount + 1);

        for (const auto& [ch, count] : charCount) {
            buckets[count].push_back(ch);
        }

        for (int i = buckets.size() - 1; i > 0; i--) {
            for (char c : buckets[i])
                result.append(i, c);
        }

        return result;
    }
};