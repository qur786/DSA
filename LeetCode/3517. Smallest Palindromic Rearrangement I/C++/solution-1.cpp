class Solution {
public:
    string countingSort(const string& s) {
        array<int, 26> countingArray{};
        int size = s.size();
        string sorted(size, ' ');

        for (const char& c : s)
            countingArray[c - 'a']++;
        for (int i = 1; i < 26; i++) {
            countingArray[i] = countingArray[i] + countingArray[i - 1];
        }
        for (int i = size - 1; i >= 0; i--) {
            int index = countingArray[s[i] - 'a'];
            sorted[index - 1] = s[i];
            countingArray[s[i] - 'a']--;
        }

        return sorted;
    }
    string smallestPalindrome(string s) {
        int size = s.size();
        int mid = size / 2;
        string firstHalf = s.substr(0, mid);
        firstHalf = countingSort(firstHalf);
        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());
        if (size % 2 != 0)
            firstHalf.push_back(s[mid]);
        return firstHalf + secondHalf;
    }
};