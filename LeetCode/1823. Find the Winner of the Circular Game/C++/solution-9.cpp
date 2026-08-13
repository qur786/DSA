class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;

        for (int i = 1; i <= n; i++)
            q.push(i);

        while (q.size() > 1) {
            int j = k - 1;
            j %= q.size();
            while (j > 0) {
                int front = q.front();
                q.pop();
                q.push(front);
                j--;
            }
            q.pop();
        }

        return q.front();
    }
};