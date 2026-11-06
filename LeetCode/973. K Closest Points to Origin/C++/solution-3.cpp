class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        auto comparator = [](const pair<long long, int>& a,
                             const pair<long long, int>& b) {
            return a.first < b.first;
        };
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       decltype(comparator)>
            pq(comparator);

        int index = 0;
        for (const auto& point : points) {
            long long x = point[0];
            long long y = point[1];
            pq.emplace(x * x + y * y, index++);
            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty()) {
            auto [dist, index] = pq.top();
            pq.pop();
            result.push_back(points[index]);
        }

        return result;
    }
};