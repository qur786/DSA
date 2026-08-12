class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> dq;
        int size = points.size();
        long long maxValue = INT_MIN;

        for (int i = 0; i < size; i++) {
            int x = points[i][0], y = points[i][1];
            int dxy = y - x;
            while (!dq.empty() && (x - dq.front().first) > k)
                dq.pop_front();
            if (!dq.empty())
                maxValue =
                    max(maxValue, (long long)(x + y + dq.front().second));
            while (!dq.empty() && dxy >= dq.back().second)
                dq.pop_back();
            dq.push_back(make_pair(x, dxy));
        }

        return maxValue;
    }
};