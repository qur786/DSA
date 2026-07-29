class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int totalCount = 0;

        for (int i = 0; i < col; i++) {
            vector<int> rowPrefixSum(row, 0);
            for (int j = i; j < col; j++) {
                int sum = 0;
                unordered_map<int, int> sumCount = {{0, 1}};
                for (int k = 0; k < row; k++) {
                    rowPrefixSum[k] += matrix[k][j];
                    sum += rowPrefixSum[k];
                    int t = sum - target;
                    if (sumCount.count(t))
                        totalCount += sumCount[t];
                    sumCount[sum]++;
                }
            }
        }

        return totalCount;
    }
};