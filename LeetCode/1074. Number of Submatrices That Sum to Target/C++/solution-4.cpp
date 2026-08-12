class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int count = 0;

        for (int i = 0; i < cols; i++) {
            vector<long long> rowPrefixSum(rows, 0);
            for (int j = i; j < cols; j++) {
                long long runningSum = 0;
                unordered_map<long long, int> sumMap = {{0, 1}};
                for (int k = 0; k < rows; k++) {
                    rowPrefixSum[k] += matrix[k][j];
                    runningSum += rowPrefixSum[k];
                    long long t = runningSum - target;

                    if (sumMap.count(t))
                        count += sumMap[t];
                    sumMap[runningSum]++;
                }
            }
        }

        return count;
    }
};