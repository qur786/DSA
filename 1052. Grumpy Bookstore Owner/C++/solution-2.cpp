class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int left = 0;
        int totalNotGrumpy = 0;
        int maxGrumpy = 0, currentGrumpy = 0;
        int size = customers.size();

        for (int right = 0; right < size; right++) {
            currentGrumpy += grumpy[right] ? customers[right] : 0;
            if ((right - left + 1) > minutes) {
                currentGrumpy -= grumpy[left] ? customers[left] : 0;
                left++;
            }

            maxGrumpy = max(maxGrumpy, currentGrumpy);
        }

        for (int i = 0; i < size; i++) {
            totalNotGrumpy += grumpy[i] == 0 ? customers[i] : 0;
        }

        return totalNotGrumpy + maxGrumpy;
    }
};