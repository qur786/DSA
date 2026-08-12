class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> d;
        int maxValue = INT_MIN;

        for (const auto& point : points) {
            int x = point[0], y = point[1], dxy = point[1] - point[0];
            while (!d.empty() && abs(d.front().second - x) > k)
                d.pop_front();
            if (!d.empty())
                maxValue = max(maxValue, x + y + d.front().first);
            while (!d.empty() && d.back().first <= dxy)
                d.pop_back();
            d.push_back(make_pair(dxy, x));
        }

        return maxValue;
    }
};