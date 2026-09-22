class Solution {
	public:
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		// code here
		int size = edges.size();
		vector<int> inDegrees(V, 0);
		vector<vector<int>> adj(V);
		vector<int> answer;
		answer.reserve(V);
		queue<int> nodes;
		
		for (int i = 0; i < size; i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			
			adj[u].push_back(v);
			inDegrees[v]++;
		}
		
		for (int i = 0; i < V; i++)
			if (!inDegrees[i])
				nodes.push(i);
		
		while (!nodes.empty()) {
			int front = nodes.front();
			nodes.pop();
			answer.push_back(front);
			
			for (int neighbor : adj[front]) {
				inDegrees[neighbor]--;
				if (!inDegrees[neighbor])
					nodes.push(neighbor);
			}
		}
		
		return answer;
	}
};
