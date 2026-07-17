class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int size = arr.size(), prefixXor = 0, count = 0;
        unordered_map<int, int> sumMap = {{0, -1}}, countMap = {{0, 1}};

        for (int i = 0; i < size; i++) {
            prefixXor ^= arr[i];

            if (sumMap.count(prefixXor))
                count += (i - 1) * countMap[prefixXor] - sumMap[prefixXor];
            sumMap[prefixXor] += i;
            countMap[prefixXor]++;
        }

        return count;
    }
};