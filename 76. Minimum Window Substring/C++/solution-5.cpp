class Solution {
public:
    string minWindow(string s, string t) {
        int sSize = s.size(), tSize = t.size();

        if (tSize > sSize)
            return "";

        int minLen = INT_MAX, minIndex = -1;
        int left = 0, tUniqChars = 0, sMatchedChars = 0;
        array<int, 128> tCount{}, sCount{};

        for (char c : t) {
            if (tCount[c] == 0)
                tUniqChars++;
            tCount[c]++;
        }

        for (int right = 0; right < sSize; right++) {
            if (tCount[s[right]] > 0) {
                sCount[s[right]]++;

                if (sCount[s[right]] == tCount[s[right]])
                    sMatchedChars++;

                while (sMatchedChars == tUniqChars) {
                    if ((right - left + 1) < minLen) {
                        minLen = right - left + 1;
                        minIndex = left;
                    }

                    if (sCount[s[left]] > 0) {
                        if (sCount[s[left]] == tCount[s[left]])
                            sMatchedChars--;
                        sCount[s[left]]--;
                    }
                    left++;
                }
            }
        }

        return minIndex == -1 ? "" : s.substr(minIndex, minLen);
    }
};