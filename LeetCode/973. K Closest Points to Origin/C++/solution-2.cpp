class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        result.reserve(k);
        auto comparator = [](const pair<long long, int>& a,
                             const pair<long long, int>& b) {
            return a.first < b.first;
        };
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       decltype(comparator)>
            pq(comparator);

        int index = 0;
        for (const auto& point : points) {
            int x = point[0], y = point[1];
            pq.emplace(x * x + y * y, index++);
            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty()) {
            auto [dist, i] = pq.top();
            result.push_back(points[i]);
            pq.pop();
        }

        return result;
    }
};