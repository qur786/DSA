class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int size = people.size();
        int left = 0, right = size - 1;
        int boats = 0;

        while (left <= right) {
            int w = people[left] + people[right];
            if (w <= limit) {
                left++;
            }
            right--;
            boats++;
        }

        return boats;
    }
};