class Solution {
private:
    void reverseStr(vector<char>& s, int index, int size) {
        if (index == size) {
            return;
        }

        char ch = s[index];
        reverseStr(s, index + 1, size);
        s[size - 1 - index] = ch;
    }

public:
    void reverseString(vector<char>& s) { reverseStr(s, 0, s.size()); }
};