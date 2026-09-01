class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int totalTime = 0;
        int size = tickets.size();

        for (int i = 0; i < size; i++) {
            if (i <= k) {
                totalTime += min(tickets[k], tickets[i]);
            } else {
                totalTime += min(tickets[k] - 1, tickets[i]);
            }
        }

        return totalTime;
    }
};