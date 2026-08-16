class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();
        vector<bool> visited(size, false);
        queue<int> nodes;
        nodes.push(0);
        visited[0] = true;

        while (!nodes.empty()) {
            int front = nodes.front();
            nodes.pop();

            for (const int n : rooms[front]) {
                if (!visited[n]) {
                    nodes.push(n);
                    visited[n] = true;
                }
            }
        }

        bool notAllVisited = any_of(visited.begin(), visited.end(),
                                    [](bool flag) { return !flag; });

        return !notAllVisited;
    }
};