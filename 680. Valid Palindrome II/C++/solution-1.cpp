class Solution {
public:
    bool isPalindrome(const string& s, int& left, int& right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }

        return true;
    }
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        bool isValid = isPalindrome(s, left, right);
        if (isValid)
            return true;

        int newLeft = left + 1, newRight = right - 1;

        return isPalindrome(s, newLeft, right) ||
               isPalindrome(s, left, newRight);
    }
};