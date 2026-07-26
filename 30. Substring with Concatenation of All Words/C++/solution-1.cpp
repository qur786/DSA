class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int strSize = s.size(), wordSize = words.size();
        unordered_map<string, int> wordMap;
        int wordLen = words[0].size();

        for (const auto& word : words)
            wordMap[word]++;
        int uniqueCount = wordMap.size();

        for (int k = 0; k < wordLen; k++) {
            int left = k;
            int uniqueWords = 0;
            unordered_map<string, int> answerMap;
            for (int i = k; i < strSize; i += wordLen) {
                string sub = s.substr(i, wordLen);
                if (wordMap.count(sub)) {
                    answerMap[sub]++;
                    if (answerMap[sub] == wordMap[sub])
                        uniqueWords++;

                    if ((i - left + 1) > wordLen * (wordSize - 1)) {
                        if (uniqueWords == uniqueCount)
                            result.push_back(left);

                        string subStr = s.substr(left, wordLen);
                        if (answerMap.count(subStr)) {
                            if (answerMap[subStr] == wordMap[subStr])
                                uniqueWords--;
                            answerMap[subStr]--;
                        }
                        left += wordLen;
                    }
                } else {
                    answerMap.clear();
                    uniqueWords = 0;
                    left = i + wordLen;
                }
            }
        }

        return result;
    }
};