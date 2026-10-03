class Solution {
public:
    vector<int> diStringMatch(string s) {
        int size = s.size();
        int left = 0, right = size;
        vector<int> result(size + 1);

        for (int i = 0; i < size; i++) {
            result[i] = s[i] == 'I' ? left++ : right--;
        }
        result[size] = left;

        return result;
    }
};