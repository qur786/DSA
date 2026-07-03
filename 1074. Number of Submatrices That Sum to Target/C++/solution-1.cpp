class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int total = 0;

        for (int i = 0; i < col; i++) {
            vector<int> rowPrefixSum(row, 0);
            for (int j = i; j < col; j++) {
                unordered_map<int, int> sumMap = {{0, 1}};
                int sum = 0;
                for (int k = 0; k < row; k++) {
                    rowPrefixSum[k] += matrix[k][j];
                    sum += rowPrefixSum[k];
                    int value = sum - target;
                    if (sumMap.count(value))
                        total += sumMap[value];
                    sumMap[sum]++;
                }
            }
        }

        return total;
    }
};