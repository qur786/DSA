class Solution {
	public:
	vector<int> bfs(vector<vector<int>> &adj) {
		// code here
		int size = adj.size();
		vector<int> result;
		result.reserve(size);
		vector<bool> visited(size, false);
		queue<int> nodes;
		
		for (int i = 0; i < size; i++) {
			if (!visited[i]) {
				visited[i] = true;
				nodes.push(i);
				
				while (!nodes.empty()) {
					int nodeCount = nodes.size();
					int front = nodes.front();
					nodes.pop();
					result.push_back(front);
					
					for (const int n : adj[front]) {
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
