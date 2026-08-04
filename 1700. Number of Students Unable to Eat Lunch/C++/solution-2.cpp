class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0, 0};

        for (int n : students)
            count[n]++;
        for (int n : sandwiches)
            if (count[n] == 0)
                break;
            else
                count[n]--;

        return count[0] + count[1];
    }
};