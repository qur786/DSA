class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int size = tickets.size(), timer = 0;

        for (int i = 0; i < size; i++) {
            if (i <= k)
                timer += min(tickets[k], tickets[i]);
            else
                timer += min(tickets[i], tickets[k] - 1);
        }

        return timer;
    }
};