class Solution {
public:
    string minWindow(string s, string t) {
        int sSize = s.size(), tSize = t.size();
        if (tSize > sSize)
            return "";

        int minIndex = -1, minLen = INT_MAX;
        int uniqueT = 0, uniqueS = 0;
        array<int, 128> tCount{}, sCount{};
        int left = 0;

        for (char c : t)
            if (tCount[c]++ == 0)
                uniqueT++;

        for (int right = 0; right < sSize; right++) {
            if (tCount[s[right]] > 0) {
                sCount[s[right]]++;
                if (sCount[s[right]] == tCount[s[right]])
                    uniqueS++;

                while (uniqueS == uniqueT) {
                    if (right - left + 1 < minLen) {
                        minIndex = left;
                        minLen = right - left + 1;
                    }
                    if (sCount[s[left]] > 0) {
                        if (sCount[s[left]] == tCount[s[left]])
                            uniqueS--;
                        sCount[s[left]]--;
                    }
                    left++;
                }
            }
        }

        return minIndex == -1 ? "" : s.substr(minIndex, minLen);
    }
};