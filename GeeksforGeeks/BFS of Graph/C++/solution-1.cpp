class Solution {
	public:
	vector<int> bfs(vector<vector<int>> &adj) {
		// code here
		if (adj.empty())
			return {};
		int size = adj.size();
		vector<bool> visited(size, false);
		vector<int> answer;
		answer.reserve(size);
		queue<int> nodes;
		nodes.push(0);
		visited[0] = true;
		
		while (!nodes.empty()) {
			int front = nodes.front(); nodes.pop();
			answer.push_back(front);
			
			for (int v : adj[front]) {
				if (!visited[v]) {
					visited[v] = true;
					nodes.push(v);
				}
			}
		}
		
		return answer;
	}
};
