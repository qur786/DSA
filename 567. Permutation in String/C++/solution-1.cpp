class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.size(), size2 = s2.size();

        if (size1 > size2)
            return false;

        unordered_map<char, int> s1Map, s2Map;
        int left = 0;

        for (char c : s1)
            s1Map[c]++;
        for (int right = 0; right < size2; right++) {
            if (s1Map.count(s2[right]))
                s2Map[s2[right]]++;

            if (right >= size1) {
                if (s1Map.count(s2[left]))
                    s2Map[s2[left]]--;
                left++;
            }

            if (s1Map == s2Map)
                return true;
        }

        return false;
    }
};