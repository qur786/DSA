class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int size = people.size();
        int left = 0, right = size - 1;
        int boatCount = 0;

        while (left <= right) {
            if ((people[left] + people[right]) <= limit) {
                left++;
            }
            right--;
            boatCount++;
        }
        return boatCount;
    }
};