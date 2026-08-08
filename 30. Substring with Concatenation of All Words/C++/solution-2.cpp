class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> org;
        int wordSize = words[0].size();
        int wordCount = words.size();
        int strSize = s.size();
        vector<int> result;

        for (const string& word : words)
            org[word]++;

        int uniqueOrg = org.size();

        for (int i = 0; i < wordSize; i++) {
            int left = i;
            unordered_map<string, int> match;
            int matchedCount = 0;
            for (int right = i; right < strSize; right += wordSize) {
                const string rightSub = s.substr(right, wordSize);

                if (org.count(rightSub)) {
                    match[rightSub]++;
                    if (match[rightSub] == org[rightSub])
                        matchedCount++;

                    if ((right - left + 1) > (wordSize * (wordCount - 1))) {
                        const string leftSub = s.substr(left, wordSize);
                        if (matchedCount == uniqueOrg)
                            result.push_back(left);
                        if (match.count(leftSub)) {
                            if (match[leftSub] == org[leftSub])
                                matchedCount--;
                            match[leftSub]--;
                        }
                        left += wordSize;
                    }

                } else {
                    match.clear();
                    left = right + wordSize;
                    matchedCount = 0;
                }
            }
        }

        return result;
    }
};