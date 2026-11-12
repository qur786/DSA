class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int size = points.size();
        auto comparator = [](const pair<long long, int>& a,
                             const pair<long long, int>& b) {
            return a.first < b.first;
        };

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       decltype(comparator)>
            pq(comparator);

        for (int i = 0; i < size; i++) {
            const auto& point = points[i];
            long long x = (long long)point[0];
            long long y = (long long)point[1];
            long long dist = x * x + y * y;
            pq.emplace(dist, i);
            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> result;
        result.reserve(k);

        while (!pq.empty()) {
            result.push_back(points[pq.top().second]);
            pq.pop();
        }

        return result;
    }
};