class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> remainderCount;
        int size = time.size(), total = 0;

        for (int i = 0; i < size; i++) {
            int target = (60 - time[i] % 60) % 60;
            if (remainderCount.count(target))
                total += remainderCount[target];
            remainderCount[time[i] % 60]++;
        }

        return total;
    }
};