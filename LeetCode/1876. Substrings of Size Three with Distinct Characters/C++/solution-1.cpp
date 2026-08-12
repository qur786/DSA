class Solution {
public:
    int countGoodSubstrings(string s) {
        int left = 0, size = s.size();
        int count = 0;
        unordered_map<char, int> charIndices;
        charIndices.reserve(26);

        for (int right = 0; right < size; right++) {
            if (charIndices.count(s[right]) && charIndices[s[right]] >= left) {
                left = charIndices[s[right]] + 1;
            }
            charIndices[s[right]] = right;
            if ((right - left + 1) >= 3)
                count++;
        }

        return count;
    }
};