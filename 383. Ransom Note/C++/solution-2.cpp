class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        array<int, 26> ransomMap{}, magazineMap{};

        for (char c : ransomNote)
            ransomMap[c - 'a']++;
        for (char c : magazine)
            if (ransomMap[c - 'a'] && magazineMap[c - 'a'] < ransomMap[c - 'a'])
                magazineMap[c - 'a']++;

        return ransomMap == magazineMap;
    }
};