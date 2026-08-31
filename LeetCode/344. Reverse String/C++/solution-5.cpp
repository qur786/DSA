class Solution {
private:
    void reverseStr(vector<char>& s, int index) {
        if (s.size() == index)
            return;
        char ch = s[index];
        reverseStr(s, index + 1);
        s[s.size() - 1 - index] = ch;
    }

public:
    void reverseString(vector<char>& s) {
        if (s.empty())
            return;
        reverseStr(s, 0);
    }
};