class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int d = 0;
        int size = courses.size();
        priority_queue<int> pq;
        sort(courses.begin(), courses.end(),
             [](auto& v1, auto& v2) { return v1[1] < v2[1]; });

        for (int i = 0; i < size; i++) {
            int duration = courses[i][0];
            int endtime = courses[i][1];

            d += duration;
            pq.push(duration);

            if (d > endtime) {
                int dur = pq.top();
                pq.pop();
                d -= dur;
            }
        }

        return pq.size();
    }
};