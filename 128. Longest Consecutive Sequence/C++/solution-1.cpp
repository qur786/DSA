class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int size = nums.size();
        int longestConsec = 0;

        for (int n : numSet) {
            if (numSet.count(n - 1))
                continue;
            int count = 0, value = n;
            while (numSet.count(value)) {
                count++;
                value++;
            }

            longestConsec = max(count, longestConsec);
        }

        return longestConsec;
    }
};