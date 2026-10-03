class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int size = people.size();
        sort(people.begin(), people.end());
        int left = 0, right = size - 1;
        int count = 0;

        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
            }
            right--;
            count++;
        }

        return count;
    }
};