class Solution {
public:
    int findTheWinner(int n, int k) {
        int size = n;
        queue<int> friends;

        for (int i = 1; i <= size; i++)
            friends.push(i);

        while (friends.size() > 1) {
            int rotationSteps = (k - 1) % friends.size();
            while (rotationSteps > 0) {
                int front = friends.front();
                friends.pop();
                friends.push(front);
                rotationSteps--;
            }
            friends.pop();
        }

        return friends.front();
    }
};