class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int size = capital.size();
        priority_queue<int> pq;

        vector<int> indices(size);
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(),
             [&](int a, int b) { return capital[a] < capital[b]; });

        int capitalIndex = 0;

        while (k > 0 && (capitalIndex < size || !pq.empty())) {
            while (capitalIndex < size && capital[indices[capitalIndex]] <= w) {
                pq.emplace(profits[indices[capitalIndex]]);
                capitalIndex += 1;
            }

            if (pq.empty())
                return w;
            w += pq.top();
            pq.pop();
            k -= 1;
        }

        return w;
    }
};