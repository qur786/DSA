class Solution {
	public:
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		vector<int> inDegrees(V, 0);
		vector<vector<int>> adj(V);
		vector<int> answer;
		answer.reserve(V);
		queue<int> nodes;
		
		for (const auto & edge : edges) {
			adj[edge[0]].push_back(edge[1]);
			inDegrees[edge[1]]++;
		}
		
		for (int i = 0; i < V; i++)
			if (!inDegrees[i])
				nodes.push(i);
		
		while (!nodes.empty()) {
			int front = nodes.front(); nodes.pop();
			answer.push_back(front);
			
			for (int child : adj[front]) {
				inDegrees[child]--;
				if (!inDegrees[child]) {
					nodes.push(child);
				}
			}
		}
		
		return answer;
	}
};
