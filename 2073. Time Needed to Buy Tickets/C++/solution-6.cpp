class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int size = tickets.size(), timer = 0;

        for (int i = 0; i < size; i++)
            q.push(i);

        while (!q.empty() && tickets[k] > 0) {
            timer++;
            int ticket = q.front();
            q.pop();
            tickets[ticket]--;
            if (tickets[ticket] > 0) {
                q.push(ticket);
            }
        }

        return timer;
    }
};