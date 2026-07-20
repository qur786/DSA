class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back('\0'); // santient character
        int left = 0, size = chars.size(); 
        int currentCharCount = 1;
        char currentChar = chars[0];

        for (int i = 1; i < size; i++) {
            if (currentChar != chars[i]) {
                chars[left++] = currentChar;
                currentChar = chars[i];

                if (currentCharCount > 1) {
                    string num = to_string(currentCharCount);
                    for (char c : num)
                        chars[left++] = c;
                }

                currentCharCount = 1;
            } else
                currentCharCount++;
        }

        chars.pop_back();

        return left;
    }
};