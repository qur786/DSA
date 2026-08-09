class Solution {
public:
    vector<int> diStringMatch(string s) {
        int size = s.size();
        int increasing = 0, decreasing = size;
        vector<int> result;
        result.reserve(size + 1);

        for (int i = 0; i < size; i++) {
            result.push_back(s[i] == 'I' ? increasing++ : decreasing--);
        }
        result.push_back(increasing);

        return result;
    }
};