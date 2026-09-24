class Solution {
	public:
	vector<int> bfs(vector<vector<int>> &adj) {
		// code here
		int size = adj.size();
		vector<bool> visited(size, false);
		vector<int> answer;
		answer.reserve(size);
		queue<int> nodes;
		nodes.push(0);
		visited[0] = true;
		
		while (!nodes.empty()) {
			auto front = nodes.front();
			nodes.pop();
			
			answer.push_back(front);
			
			for (int child : adj[front]) {
				if (!visited[child]) {
					visited[child] = true;
					nodes.push(child);
				}
			}
		}
		
		return answer;
	}
};
