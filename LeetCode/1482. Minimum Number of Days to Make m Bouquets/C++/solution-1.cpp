class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay, int bReq, int fReq, int days) {
        int totalB = 0, currentStreak = 0;

        for (int day : bloomDay) {
            if (day <= days)
                currentStreak += 1;
            else
                currentStreak = 0;

            if (currentStreak == fReq) {
                currentStreak = 0;
                totalB += 1;
            }
        }

        return totalB >= bReq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        auto [minIt, maxIt] = minmax_element(bloomDay.begin(), bloomDay.end());
        int low = *minIt, high = *maxIt, result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};