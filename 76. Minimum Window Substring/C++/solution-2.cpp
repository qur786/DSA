class Solution {
public:
    string minWindow(string s, string t) {
        int sSize = s.size(), tSize = t.size();

        if (tSize > sSize)
            return "";

        int minStartIndex = -1, minLen = INT_MAX;
        int left = 0;
        array<int, 128> tCount{}, sCount{};
        int uniqT = 0, uniqS = 0;

        for (char c : t) {
            if (tCount[c] == 0)
                uniqT++;
            tCount[c]++;
        }

        for (int right = 0; right < sSize; right++) {
            if (tCount[s[right]] > 0) {
                sCount[s[right]]++;
                if (sCount[s[right]] == tCount[s[right]])
                    uniqS++;

                while (uniqS == uniqT) {
                    if ((right - left + 1) < minLen) {
                        minLen = right - left + 1;
                        minStartIndex = left;
                    }
                    if (sCount[s[left]] > 0) {
                        if (sCount[s[left]] == tCount[s[left]])
                            uniqS--;
                        sCount[s[left]]--;
                    }
                    left++;
                }
            }
        }

        return minStartIndex == -1 ? "" : s.substr(minStartIndex, minLen);
    }
};