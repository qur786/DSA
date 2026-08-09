class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        array<int, 128> rCount{}, mCount{};
        int rUnique = 0, mUnique = 0;

        for (int c : ransomNote)
            if (rCount[c]++ == 0)
                rUnique++;
        for (int c : magazine) {
            mCount[c]++;
            if (rCount[c] > 0 && mCount[c] == rCount[c])
                mUnique++;
            if (rUnique == mUnique)
                return true;
        }

        return false;
    }
};