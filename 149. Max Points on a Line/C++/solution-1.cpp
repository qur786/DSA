class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int size = points.size();
        int maxSlopLines = 0;
        for (int i = 0; i < size; i++) {
            unordered_map<string, int> slopeMap;
            int localMax = 0, duplicates = 1;
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < size; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dy = y2 - y1, dx = x2 - x1;

                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }
                if (dx < 0) {
                    dy = -dy;
                    dx = -dx;
                } else if (dx == 0)
                    dy = abs(dy);

                int g = gcd(dx, dy);

                string slop = to_string(dx / g) + "_" + to_string(dy / g);

                slopeMap[slop]++;
                localMax = max(localMax, slopeMap[slop]);
            }
            maxSlopLines = max(maxSlopLines, localMax + duplicates);
        }

        return maxSlopLines;
    }
};