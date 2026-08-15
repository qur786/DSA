class Solution {
public:
    vector<int> diStringMatch(string s) {
        int size = s.size();
        int i = 0, d = size;
        vector<int> result(size + 1);

        int curr = 0;
        for (char c : s)
            if (c == 'I')
                result[curr++] = i++;
            else
                result[curr++] = d--;

        result[curr] = i;

        return result;
    }
};