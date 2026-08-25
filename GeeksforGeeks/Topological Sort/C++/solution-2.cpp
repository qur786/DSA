class Solution {
	public:
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		// code here
		vector<int> inDegrees(V, 0);
		vector<vector<int>> adj(V);
		queue<int> nodes;
		vector<int> result;
		result.reserve(V);
		
		for (const auto & edge : edges) {
			adj[edge[0]].push_back(edge[1]);
			inDegrees[edge[1]]++;
		}
		
		for (int i = 0; i < V; i++) if (!inDegrees[i])
			nodes.push(i);
		
		while (!nodes.empty()) {
			int node = nodes.front(); nodes.pop();
			result.push_back(node);
			
			for (int child : adj[node]) {
				inDegrees[child]--;
				if (!inDegrees[child])
					nodes.push(child);
			}
		}
		
		return result;
	}
};
