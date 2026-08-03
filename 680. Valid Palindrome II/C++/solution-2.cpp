class Solution {
public:
    bool checkPalindrome(const string& s, int& left, int& right) {
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
        if (checkPalindrome(s, left, right))
            return true;
        int newLeft = left + 1, newRight = right - 1;
        return checkPalindrome(s, newLeft, right) ||
               checkPalindrome(s, left, newRight);
    }
};