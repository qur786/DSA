class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int size = courses.size();
        priority_queue<int> pq;
        sort(courses.begin(), courses.end(),
             [&](const auto& a, const auto& b) { return a[1] < b[1]; });

        long long t = 0;

        for (int i = 0; i < size; i++) {
            t += courses[i][0];
            pq.push(courses[i][0]);

            if (t > courses[i][1]) {
                t -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};