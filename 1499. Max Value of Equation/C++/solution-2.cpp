class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int maxValue = INT_MIN;
        int size = points.size();
        deque<pair<int, int>> monotonicDecreasingQ; // x, y - x;

        for (int right = 0; right < size; right++) {
            int x = points[right][0], y = points[right][1];
            int ydiffx = y - x;
            while (!monotonicDecreasingQ.empty() &&
                   abs(x - monotonicDecreasingQ.front().first) > k) {
                monotonicDecreasingQ.pop_front();
            }
            if (!monotonicDecreasingQ.empty())
                maxValue =
                    max(maxValue, x + y + monotonicDecreasingQ.front().second);
            while (!monotonicDecreasingQ.empty() &&
                   ydiffx >= monotonicDecreasingQ.back().second) {
                monotonicDecreasingQ.pop_back();
            }

            monotonicDecreasingQ.push_back(make_pair(x, ydiffx));
        }

        return maxValue;
    }
};