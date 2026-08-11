class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                      'A', 'E', 'I', 'O', 'U'};

        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (!vowels.count(s[left]) && left < right)
                left++;
            while (!vowels.count(s[right]) && left < right)
                right--;
            if (left >= right)
                return s;
            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }
};