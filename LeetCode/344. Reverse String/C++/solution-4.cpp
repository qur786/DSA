class Solution {
private:
    void reverse(vector<char>& s, int size, int index) {
        if (index == -1)
            return;

        char ch = s[size - 1 - index];
        reverse(s, size, index - 1);
        s[index] = ch;
    }

public:
    void reverseString(vector<char>& s) { reverse(s, s.size(), s.size() - 1); }
};