class Solution {
public:
    bool isAnagram(string s, string t) {
        int sSize = s.size(), tSize = t.size();

        if (sSize != tSize)
            return false;

        array<int, 128> sCount{}, tCount{};

        for (int c : s)
            sCount[c]++;
        for (int c : t)
            tCount[c]++;

        return sCount == tCount;
    }
};