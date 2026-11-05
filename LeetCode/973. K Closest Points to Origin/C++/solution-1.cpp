class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        result.reserve(k);
        auto comparator = [](const pair<long long, long long>& a,
                             const pair<long long, long long>& b) {
            long long p1 = a.first * a.first + a.second * a.second;
            long long p2 = b.first * b.first + b.second * b.second;

            return p1 < p2;
        };
        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>, decltype(comparator)>
            pq(comparator);

        for (const auto& point : points) {
            int x = point[0], y = point[1];
            pq.emplace(x, y);
            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty()) {
            auto [x, y] = pq.top();
            result.push_back({(int)x, (int)y});
            pq.pop();
        }

        return result;
    }
};