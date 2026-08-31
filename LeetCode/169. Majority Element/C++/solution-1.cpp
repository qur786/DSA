class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj;
        int count = 0;

        for (int n : nums) {
            if (!count)
                maj = n;
            if (maj == n)
                count++;
            else
                count--;
        }

        return maj;
    }
};