class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sSize = s.size(), pSize = p.size(), left = 0;
        vector<int> result;

        if (pSize > sSize)
            return {};

        unordered_map<char, int> sMap, pMap;

        for (char c : p)
            pMap[c]++;
        for (int i = 0; i < sSize; i++) {
            if (pMap.count(s[i]))
                sMap[s[i]]++;

            if (i >= pSize) {
                if (pMap.count(s[left]))
                    sMap[s[left]]--;
                left++;
            }

            if (sMap == pMap)
                result.push_back(left);
        }

        return result;
    }
};