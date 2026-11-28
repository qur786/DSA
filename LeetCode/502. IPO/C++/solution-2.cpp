class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int size = profits.size();
        priority_queue<int> pq;
        vector<int> capitalIndices(size);
        iota(capitalIndices.begin(), capitalIndices.end(), 0);
        sort(capitalIndices.begin(), capitalIndices.end(),
             [&](int a, int b) { return capital[a] < capital[b]; });
        int capitalIndex = 0;

        while (k > 0 && (!pq.empty() || capitalIndex < size)) {
            while (capitalIndex < size &&
                   capital[capitalIndices[capitalIndex]] <= w) {
                pq.push(profits[capitalIndices[capitalIndex]]);
                capitalIndex += 1;
            }
            if (pq.empty())
                return w;
            k -= 1;
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};