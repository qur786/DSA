class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sSize = s.size(), pSize = p.size();
        if (pSize > sSize)
            return {};

        array<int, 26> sCount{}, pCount{};

        int left = 0;
        vector<int> result;

        for (char c : p)
            pCount[c - 'a']++;
        for (int right = 0; right < sSize; right++) {
            sCount[s[right] - 'a']++;

            while (right - left + 1 > pSize) {
                sCount[s[left] - 'a']--;
                left++;
            }

            if (sCount == pCount)
                result.push_back(left);
        }

        return result;
    }
};