class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if (rooms.empty())
            return true;

        int size = rooms.size();
        vector<bool> visited(size, false);
        queue<int> nodes;
        nodes.push(0);
        visited[0] = true;

        while (!nodes.empty()) {
            int front = nodes.front();
            nodes.pop();
            for (int r : rooms[front]) {
                if (!visited[r]) {
                    visited[r] = true;
                    nodes.push(r);
                }
            }
        }

        bool notVisited = any_of(visited.begin(), visited.end(),
                                 [](bool value) { return !value; });

        return !notVisited;
    }
};