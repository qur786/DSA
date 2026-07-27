class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelSet;
        int jewelCount = 0;

        for (char c : jewels)
            jewelSet.insert(c);

        for (char c : stones)
            if (jewelSet.count(c))
                jewelCount++;

        return jewelCount;
    }
};