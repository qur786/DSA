class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int studentsCount = students.size(), sandCount = sandwiches.size();
        queue<int> sandQ, stuQ;

        for (int s : students) {
            stuQ.push(s);
        }
        for (int s : sandwiches) {
            sandQ.push(s);
        }

        int studentsEaten = 0, studentsWaiting = 0;

        while (!sandQ.empty() && studentsWaiting != stuQ.size()) {
            if (sandQ.front() == stuQ.front()) {
                sandQ.pop();
                stuQ.pop();
                studentsEaten++;
                studentsWaiting = 0;
            } else {
                int front = stuQ.front();
                stuQ.pop();
                stuQ.push(front);
                studentsWaiting++;
            }
        }

        return studentsWaiting;
    }
};