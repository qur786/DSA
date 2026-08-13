class Solution {
	public:
	vector<int> bfs(vector<vector<int>> &adj) {
		// code here
		int nodeCount = adj.size();
		vector<bool> visited(nodeCount, false);
		queue<int> nodes;
		vector<int> result;
		result.reserve(nodeCount);
		
		for (int i = 0; i < nodeCount; i++) {
			if (!visited[i]) {
				visited[i] = true;
				nodes.push(i);
				
				while (!nodes.empty()) {
					int front = nodes.front(); nodes.pop();
					result.push_back(front);
					for (int n : adj[front]) {
						if (!visited[n]) {
							visited[n] = true;
							nodes.push(n);
						}
					}
				}
			}
		}
		
		return result;
	}
};
