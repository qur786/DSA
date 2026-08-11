class Solution {
public:
    int maximumHistogramArea(vector<int>& nums) {
        stack<int> monotonicIncreasingNumIndces;
        nums.push_back(0); // Santient value;
        int size = nums.size(), maxArea = 0;

        for (int right = 0; right < size; right++) {
            while (!monotonicIncreasingNumIndces.empty() &&
                   nums[monotonicIncreasingNumIndces.top()] > nums[right]) {
                int currentIndex = monotonicIncreasingNumIndces.top();
                monotonicIncreasingNumIndces.pop();
                int height = nums[currentIndex];
                int left = monotonicIncreasingNumIndces.empty()
                               ? -1
                               : monotonicIncreasingNumIndces.top();
                int width = right - left - 1;

                maxArea = max(maxArea, height * width);
            }
            monotonicIncreasingNumIndces.push(right);
        }

        nums.pop_back();

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> histograms(cols, 0);

        int maxArea = 0;
        for (const auto& row : matrix) {
            for (int i = 0; i < cols; i++) {
                if (row[i] == '0')
                    histograms[i] = 0;
                else
                    histograms[i]++;
            }
            maxArea = max(maxArea, maximumHistogramArea(histograms));
        }

        return maxArea;
    }
};