class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.size(), size2 = s2.size();

        if (size1 > size2)
            return false;

        int left = 0;
        array<int, 26> s1Count{}, s2Count{};

        for (char c : s1)
            s1Count[c - 'a']++;

        for (int right = 0; right < size2; right++) {
            s2Count[s2[right] - 'a']++;

            while ((right - left + 1) > size1) {
                s2Count[s2[left] - 'a']--;
                left++;
            }

            if (s1Count == s2Count)
                return true;
        }

        return false;
    }
};