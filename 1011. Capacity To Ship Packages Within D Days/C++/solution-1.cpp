class Solution {
public:
    bool canShipPackages(vector<int>& weights, int days, int capacity) {
        long long totalDays = 1, currentWeight = 0;

        for (int weight : weights) {
            if ((currentWeight + weight) > capacity) {
                totalDays += 1;
                currentWeight = weight;
            } else {
                currentWeight += weight;
            }
        }

        return totalDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long minCapacity = *max_element(weights.begin(), weights.end());
        long long maxCapacity = accumulate(weights.begin(), weights.end(), 0);
        long long result = 0;

        while (minCapacity <= maxCapacity) {
            int mid = minCapacity + (maxCapacity - minCapacity) / 2;

            if (canShipPackages(weights, days, mid)) {
                result = mid;
                maxCapacity = mid - 1;
            } else {
                minCapacity = mid + 1;
            }
        }

        return result;
    }
};