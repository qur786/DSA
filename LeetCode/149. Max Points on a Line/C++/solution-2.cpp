class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxPoints = 0;
        int pointCount = points.size();

        for (int i = 0; i < pointCount; i++) {
            int localMaxSlope = 0;
            unordered_map<string, int> slopeCount;
            int x1 = points[i][0], y1 = points[i][1];
            int duplicates = 1;
            for (int j = i + 1; j < pointCount; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dx = x2 - x1;
                int dy = y2 - y1;

                if (dx == 0 && dy == 0)
                    duplicates++;

                if (dx == 0) {
                    dy = abs(dy);
                } else if (dx < 0) {
                    dy = -dy;
                    dx = -dx;
                }

                int g = gcd(dx, dy);
                string slope = to_string(dx / g) + "_" + to_string(dy / g);
                slopeCount[slope]++;
                localMaxSlope = max(localMaxSlope, slopeCount[slope]);
            }
            maxPoints = max(maxPoints, localMaxSlope + duplicates);
        }

        return maxPoints;
    }
};