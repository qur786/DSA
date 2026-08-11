class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int timeTaken = 0, size = tickets.size();
        queue<int> counter;

        for (int i = 0; i < size; i++)
            counter.push(i);

        while (tickets[k] > 0) {
            timeTaken++;
            tickets[counter.front()]--;
            if (tickets[counter.front()] != 0)
                counter.push(counter.front());
            counter.pop();
        }

        return timeTaken;
    }
};