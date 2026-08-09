class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currOnes = 0, maxOnes = 0;

        for (int n : nums) {
            if (n == 1) {
                currOnes++;
                maxOnes = max(maxOnes, currOnes);
            } else
                currOnes = 0;
        }

        return maxOnes;
    }
};