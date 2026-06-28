class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int currStreak = 1, currMax = 1, currFr = fruits[0], prevFr = -1,
            maxFr = 1, size = fruits.size();
        for (int i = 1; i < size; i++) {
            int fruit = fruits[i];
            if (fruit == prevFr || fruit == currFr) {
                currMax++;
            } else {
                currMax = currStreak + 1;
            }

            if (fruit == currFr) {
                currStreak++;
            } else {
                currStreak = 1;
                prevFr = currFr;
                currFr = fruit;
            }

            maxFr = max(maxFr, currMax);
        }

        return maxFr;
    }
};