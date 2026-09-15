class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int totalTime = 0;
        int size = tickets.size();

        for (int i = 0; i < size; i++) {
            totalTime +=
                min(tickets[i], i <= k ? tickets[k] : (tickets[k] - 1));
        }

        return totalTime;
    }
};