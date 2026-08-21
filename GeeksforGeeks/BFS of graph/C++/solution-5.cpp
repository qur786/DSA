class Solution {
	public:
	vector<int> bfs(vector<vector<int>> &adj) {
		// code here
		int size = adj.size();
		vector<int> result;
		result.reserve(size);
		queue<int> nodes;
		nodes.push(0);
		vector<bool> visited(size, false);
		visited[0] = true;
		result.push_back(0);
		
		while (!nodes.empty()) {
			auto front = nodes.front(); nodes.pop();
			for (int value : adj[front]) {
				if (!visited[value]) {
					visited[value] = true;
					result.push_back(value);
					nodes.push(value);
				}
			}
		}
		
		return result;
	}
};
