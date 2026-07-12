class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int prevFruit = -1, currFruit = -1;
        int currStreak = 0, currValue = 0, maxValue = 0;
        int size = fruits.size();

        for (int i = 0; i < size; i++) {
            if (fruits[i] == currFruit || fruits[i] == prevFruit) {
                currValue++;
            } else {
                currValue = currStreak + 1;
            }
            if (fruits[i] == currFruit)
                currStreak++;
            else {
                currStreak = 1;
                prevFruit = currFruit;
                currFruit = fruits[i];
            }
            maxValue = max(maxValue, currValue);
        }

        return maxValue;
    }
};