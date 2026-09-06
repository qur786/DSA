class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int size = points.size();
        deque<pair<int, int>> dq;
        int maxSum = INT_MIN;

        for (int i = 0; i < size; i++) {
            int x = points[i][0], y = points[i][1];
            int dxy = y - x;
            while (!dq.empty() && (x - dq.front().first) > k)
                dq.pop_front();
            if (!dq.empty())
                maxSum = max(maxSum, x + y + dq.front().second);
            while (!dq.empty() && dq.back().second <= dxy)
                dq.pop_back();
            dq.emplace_back(x, dxy);
        }

        return maxSum;
    }
};