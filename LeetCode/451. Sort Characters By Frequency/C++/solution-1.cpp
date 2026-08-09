class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> charCount;
        int maxCount = 0, size = s.size();
        string result;
        result.reserve(size);

        for (char c : s) {
            charCount[c]++;
            maxCount = max(maxCount, charCount[c]);
        }

        vector<vector<char>> buckets(maxCount + 1);

        for (const auto& [ch, count] : charCount) {
            buckets[count].push_back(ch);
        }

        for (int i = maxCount; i >= 0; i--) {
            for (char c : buckets[i]) {
                result.append(i, c);
            }
        }

        return result;
    }
};