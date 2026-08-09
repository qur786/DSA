class Solution {
public:
    int joshephus(vector<int>& values, int startIndex, int k) {
        while (values.size() > 1) {
            int deleteIndex = (startIndex + k) % values.size();
            values.erase(values.begin() + deleteIndex);
            startIndex = deleteIndex;
        }

        return values[0];
    }
    int findTheWinner(int n, int k) {
        vector<int> values;
        values.reserve(n);

        for (int i = 1; i <= n; i++)
            values.push_back(i);

        return joshephus(values, 0, k - 1);
    }
};