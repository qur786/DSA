class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        vector<int> sortedHeights(heights.begin(), heights.end());
        sort(sortedHeights.begin(), sortedHeights.end());
        int size = heights.size();

        for (int i = 0; i < size; i++)
            count += sortedHeights[i] != heights[i];

        return count;
    }
};