class Solution {
public:
    int compress(vector<char>& chars) {
        int left = 0, currentCount = 1, size = chars.size();

        for (int right = 1; right < size; right++) {
            if (chars[right] == chars[right - 1]) {
                currentCount++;
            } else {
                chars[left++] = chars[right - 1];
                if (currentCount > 1) {
                    string currentCountString = to_string(currentCount);
                    for (char c : currentCountString) {
                        chars[left++] = c;
                    }
                }
                currentCount = 1;
            }
        }

        chars[left++] = chars[size - 1];
        if (currentCount > 1) {
            string currentCountString = to_string(currentCount);
            for (char c : currentCountString) {
                chars[left++] = c;
            }
        }

        return left;
    }
};