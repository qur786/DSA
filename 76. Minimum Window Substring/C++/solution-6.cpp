class Solution {
public:
    string minWindow(string s, string t) {
        int sSize = s.size(), tSize = t.size();
        if (tSize > sSize)
            return "";

        int matchedS = 0, left = 0;
        int minIndex = -1, minLen = INT_MAX;
        unordered_map<char, int> tMap, sMap;

        for (char c : t)
            tMap[c]++;

        for (int right = 0; right < sSize; right++) {
            if (tMap.count(s[right])) {
                sMap[s[right]]++;
                if (tMap[s[right]] == sMap[s[right]])
                    matchedS++;

                while (matchedS == tMap.size()) {
                    if (minLen > (right - left + 1)) {
                        minIndex = left;
                        minLen = right - left + 1;
                    }
                    if (sMap.count(s[left])) {
                        if (sMap[s[left]] == tMap[s[left]])
                            matchedS--;
                        sMap[s[left]]--;
                    }
                    left++;
                }
            }
        }

        return minIndex == -1 ? "" : s.substr(minIndex, minLen);
    }
};