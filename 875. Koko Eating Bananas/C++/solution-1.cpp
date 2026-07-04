class Solution {
public:
    /**
     * The problem can be moulded into finding the minimum number of banana per
     * hour to eat the whole piles with binary search as eating banana of the
     * whole piles is monotonic.
     */
    bool canEatBanana(vector<int>& piles, int hours, int banana) {
        long long currentHour = 0, totalHours = 0;

        for (int pile : piles) {
            totalHours += ((long long)pile + banana - 1) / banana;
        }

        return totalHours <= hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int minBanana = 1, maxBanana = *max_element(piles.begin(), piles.end());
        int result = 0;

        while (minBanana <= maxBanana) {
            int mid = minBanana + (maxBanana - minBanana) / 2;

            if (canEatBanana(piles, h, mid)) {
                result = mid;
                maxBanana = mid - 1;
            } else {
                minBanana = mid + 1;
            }
        }

        return result;
    }
};