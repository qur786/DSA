class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();
        vector<bool> visited(size, false);
        visited[0] = true;
        queue<int> nodes;
        nodes.push(0);

        while (!nodes.empty()) {
            auto front = nodes.front();
            nodes.pop();

            for (int value : rooms[front]) {
                if (!visited[value]) {
                    visited[value] = true;
                    nodes.push(value);
                }
            }
        }

        bool isAllNotVisited = any_of(visited.begin(), visited.end(),
                                      [](bool flag) { return !flag; });

        return !isAllNotVisited;
    }
};