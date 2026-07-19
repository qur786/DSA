class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expectedHeights(heights.begin(), heights.end());
        sort(expectedHeights.begin(), expectedHeights.end());
        int count = 0, size = heights.size();

        for (int i = 0; i < size; i++) {
            if (heights[i] != expectedHeights[i])
                count++;
        }

        return count;
    }
};