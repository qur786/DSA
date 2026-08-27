class Solution {
	public:
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		// code here
		vector<vector<int>> adj(V);
		vector<int> inDegrees(V, 0);
		vector<int> answer;
		answer.reserve(V);
		queue<int> nodes;
		
		for (const auto & edge : edges) {
			int x = edge[0], y = edge[1];
			adj[x].push_back(y);
			inDegrees[y]++;
		}
		
		for (int i = 0; i < V; i++) {
			if (!inDegrees[i])
				nodes.push(i);
		}
		
		while (!nodes.empty()) {
			int front = nodes.front(); nodes.pop();
			
			answer.push_back(front);
			
			for (int n : adj[front]) {
				inDegrees[n]--;
				if (!inDegrees[n])
					nodes.push(n);
			}
		}
		
		return answer;
	}
};
