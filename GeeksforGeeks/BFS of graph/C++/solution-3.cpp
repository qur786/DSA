class Solution {
	public:
	vector<int> bfs(vector<vector<int>> &adj) {
		int size = adj.size();
		vector<int> result;
		result.reserve(size);
		queue<int> nodes;
		vector<bool> visited(size, false);
		
		for (int i = 0; i < size; i++) {
			if (!visited[i]) {
				nodes.push(i);
				visited[i] = true;
				while (!nodes.empty()) {
					int front = nodes.front();
					nodes.pop();
					result.push_back(front);
					for (int j = 0; j < adj[front].size(); j++) {
						if (!visited[adj[front][j]]) {
							nodes.push(adj[front][j]);
							visited[adj[front][j]] = true;
						}
					}
				}
			}
		}
		
		return result;
	}
};
