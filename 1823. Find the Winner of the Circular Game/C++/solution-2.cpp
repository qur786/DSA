class Solution {
public:
    int joshephus(vector<int>& values, int startIndex, int k) {
        if (values.size() == 1)
            return values[0];

        int deleteIndex = (startIndex + k) % values.size();
        values.erase(values.begin() + deleteIndex);

        return joshephus(values, deleteIndex, k);
    }
    int findTheWinner(int n, int k) {
        vector<int> values;
        values.reserve(n);

        for (int i = 1; i <= n; i++)
            values.push_back(i);

        return joshephus(values, 0, k - 1);
    }
};