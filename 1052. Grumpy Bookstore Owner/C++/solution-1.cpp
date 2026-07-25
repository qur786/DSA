class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int left = 0, size = grumpy.size();
        long long maxPeople = 0, currentPeople = 0;

        for (int right = 0; right < size; right++) {
            currentPeople += grumpy[right] == 1 ? customers[right] : 0;

            if ((right - left + 1) > minutes) {
                currentPeople -= grumpy[left] == 1 ? customers[left] : 0;
                left++;
            }

            if ((right - left + 1) == minutes)
                maxPeople = max(maxPeople, currentPeople);
        }

        long long totalBase = 0;

        for (int i = 0; i < size; i++)
            totalBase += grumpy[i] == 0 ? customers[i] : 0;

        return totalBase + maxPeople;
    }
};