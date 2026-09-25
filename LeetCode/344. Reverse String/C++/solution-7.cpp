class Solution {
private:
    void reverse(vector<char>& s, int size, int index) {
        if (index == size)
            return;

        char ch = s[index];
        reverse(s, size, index + 1);
        s[size - 1 - index] = ch;
    }

public:
    void reverseString(vector<char>& s) { reverse(s, s.size(), 0); }
};