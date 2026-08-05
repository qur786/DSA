class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int timeTaken = 0, size = tickets.size();

        for (int i = 0; i < size; i++) {
            if (i <= k) {
                timeTaken += min(tickets[k], tickets[i]);
            } else {
                timeTaken += min(tickets[k] - 1, tickets[i]);
            }
        }

        return timeTaken;
    }
};