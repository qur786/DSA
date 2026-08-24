class Solution {
	public:
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		// code here
		vector<int> inDegrees(V, 0);
		vector<int> topologicalSort;
		topologicalSort.reserve(V);
		queue<int> nodes;
		vector<vector<int>> adj(V);
		
		for (const auto & edge : edges)
			adj[edge[0]].push_back(edge[1]);
		
		for (const auto & edge : adj)
			for (int n : edge)
				inDegrees[n]++;
		
		for (int i = 0; i < V; i++)
			if (!inDegrees[i])
				nodes.push(i);
		
		while (!nodes.empty()) {
			auto front = nodes.front();
			nodes.pop();
			topologicalSort.push_back(front);
			
			for (int n : adj[front]) {
				inDegrees[n]--;
				if (!inDegrees[n])
					nodes.push(n);
			}
			
		}
		
		return topologicalSort;
	}
};
