class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();
        vector<bool> visited(size, 0);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            for (int r : rooms[front]) {
                if (!visited[r]) {
                    visited[r] = true;
                    q.push(r);
                }
            }
        }

        bool notAllVisited = any_of(visited.begin(), visited.end(),
                                    [](bool flag) { return !flag; });

        return !notAllVisited;
    }
};