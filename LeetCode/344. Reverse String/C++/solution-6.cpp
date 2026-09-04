class Solution {
private:
    void reverse(vector<char>& s, int index, int size) {
        if (index == size)
            return;
        char ch = s[index];
        reverse(s, index + 1, size);
        s[size - 1 - index] = ch;
    }

public:
    void reverseString(vector<char>& s) { reverse(s, 0, s.size()); }
};