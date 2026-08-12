class Solution {
public:
    string minWindow(string s, string t) {
        array<int, 128> sCount{}, tCount{};
        int tSize = t.size(), sSize = s.size(), left = 0, minLen = INT_MAX,
            minIndex = -1, tChars = 0, sUniqueChars = 0;

        if (tSize > sSize)
            return "";

        for (char ch : t) {
            if (tCount[ch] == 0)
                tChars++;
            tCount[ch]++;
        }

        for (int right = 0; right < sSize; right++) {
            if (tCount[s[right]] > 0) {
                sCount[s[right]]++;
                if (sCount[s[right]] == tCount[s[right]])
                    sUniqueChars++;
                while (sUniqueChars == tChars) {
                    if ((right - left + 1) < minLen) {
                        minLen = right - left + 1;
                        minIndex = left;
                    }
                    if (sCount[s[left]] > 0) {
                        if (sCount[s[left]] == tCount[s[left]])
                            sUniqueChars--;
                        sCount[s[left]]--;
                    }
                    left += 1;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minIndex, minLen);
    }
};