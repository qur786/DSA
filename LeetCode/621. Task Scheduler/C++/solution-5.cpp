class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxFreq = 0, maxFreqCount = 0;
        unordered_map<char, int> charCount;

        for (char c : tasks)
            maxFreq = max(maxFreq, ++charCount[c]);
        for (auto& [ch, count] : charCount)
            if (count == maxFreq)
                maxFreqCount += 1;

        int duration = (maxFreq - 1) * (n + 1) + maxFreqCount;

        return max(static_cast<int>(tasks.size()), duration);
    }
};