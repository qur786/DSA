class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int size = tickets.size();
        int totalTime = 0;

        for (int i = 0; i < size; i++)
            q.push(i);

        while (tickets[k] > 0) {
            int front = q.front();
            q.pop();
            tickets[front]--;
            if (tickets[front])
                q.push(front);
            totalTime += 1;
        }

        return totalTime;
    }
};