class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, int> sumIndices = {{0, -1}}, countMap = {{0, 1}};
        int prefixXor = 0, size = arr.size(), total = 0;

        for (int i = 0; i < size; i++) {
            prefixXor ^= arr[i];
            if (sumIndices.count(prefixXor)) {
                total += countMap[prefixXor] * (i - 1) - sumIndices[prefixXor];
            }
            countMap[prefixXor]++;
            sumIndices[prefixXor] += i;
        }

        return total;
    }
};