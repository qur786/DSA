class Solution {
public:
    string minWindow(string s, string t) {
        int sSize = s.size(), tSize = t.size();

        if (tSize > sSize)
            return "";
        int minLen = INT_MAX, minIndex = -1;
        unordered_map<char, int> sMap, tMap;
        int uniqeT = 0, uniqeS = 0, left = 0;

        for (char c : t) {
            if (tMap[c] == 0)
                uniqeT++;
            tMap[c]++;
        }

        for (int right = 0; right < sSize; right++) {
            if (tMap.count(s[right])) {
                sMap[s[right]]++;
                if (sMap[s[right]] == tMap[s[right]])
                    uniqeS++;

                while (uniqeS == uniqeT) {
                    if ((right - left + 1) < minLen) {
                        minLen = right - left + 1;
                        minIndex = left;
                    }
                    if (sMap.count(s[left])) {
                        if (sMap[s[left]] == tMap[s[left]])
                            uniqeS--;
                        sMap[s[left]]--;
                    }
                    left++;
                }
            }
        }

        return minIndex == -1 ? "" : s.substr(minIndex, minLen);
    }
};