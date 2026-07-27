class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxConsec = 0;

        for (int n : numSet) {
            if (numSet.count(n - 1))
                continue;

            int value = n, count = 0;
            while (numSet.count(value)) {
                value++;
                count++;
            }
            maxConsec = max(maxConsec, count);
        }

        return maxConsec;
    }
};