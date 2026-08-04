class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int timer = 0, size = tickets.size();
        queue<int> line;

        for (int i = 0; i < size; i++)
            line.push(i);

        while (tickets[k] > 0) {
            timer += 1;
            int front = line.front();
            line.pop();
            tickets[front] -= 1;
            if (tickets[front] > 0)
                line.push(front);
        }

        return timer;
    }
};