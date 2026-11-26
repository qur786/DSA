class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> charCount;
        int maxFreq = 0;
        int maxFreqCount = 0;

        for (char c : tasks) {
            maxFreq = max(maxFreq, ++charCount[c]);
        }

        for (const auto& [ch, count] : charCount) {
            if (count == maxFreq)
                maxFreqCount++;
        }

        int duration = (maxFreq - 1) * (n + 1) + maxFreqCount;

        return max(static_cast<int>(tasks.size()), duration);
    }
};