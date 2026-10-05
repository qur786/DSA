class Solution {
	public:
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		// code here
		vector<vector<int>> adj(V);
		vector<int> inDegrees(V, 0);
		queue<int> nodes;
		vector<int> result;
		result.reserve(V);
		
		for (const auto & edge : edges) {
			int u = edge[0], v = edge[1];
			adj[u].push_back(v);
			inDegrees[v]++;
		}
		
		for (int i = 0; i < V; i++) {
			if (!inDegrees[i])
				nodes.push(i);
		}
		
		while (!nodes.empty()) {
			auto front = nodes.front(); nodes.pop();
			result.push_back(front);
			
			for (int child : adj[front]) {
				inDegrees[child]--;
				if (!inDegrees[child])
					nodes.push(child);
			}
		}
		
		return result;
	}
};
