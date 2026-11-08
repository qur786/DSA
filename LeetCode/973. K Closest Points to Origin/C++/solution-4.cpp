class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int size = points.size();
        vector<vector<int>> result;
        result.reserve(k);
        auto comparator = [](const pair<long long, int>& a,
                             const pair<long long, int>& b) {
            return a.first < b.first;
        };
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       decltype(comparator)>
            pq(comparator);

        for (int i = 0; i < size; i++) {
            pq.emplace(
                points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty()) {
            result.push_back(points[pq.top().second]);
            pq.pop();
        }

        return result;
    }
};