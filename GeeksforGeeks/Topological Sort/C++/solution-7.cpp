class Solution {
	public:
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		// code here
		vector<int> indegrees(V, 0);
		vector<vector<int>> adj(V);
		queue<int> nodes;
		vector<int> answer;
		answer.reserve(V);
		
		for (const auto & edge : edges) {
			int u = edge[0], v = edge[1];
			indegrees[v] += 1;
			adj[u].push_back(v);
		}
		
		for (int i = 0; i < V; i++) {
			if (!indegrees[i])
				nodes.emplace(i);
		}
		
		while (!nodes.empty()) {
			auto node = nodes.front(); nodes.pop();
			answer.push_back(node);
			
			for (int child : adj[node]) {
				indegrees[child]--;
				if (!indegrees[child])
					nodes.emplace(child);
			}
		}
		
		return answer;
	}
};
