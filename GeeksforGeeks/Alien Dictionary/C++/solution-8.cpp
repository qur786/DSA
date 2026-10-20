class Solution {
	public:
	string findOrder(vector<string> &words) {
		// code here
		vector<int> indegrees(26, -1);
		vector<vector<int>> adj(26);
		int uniq = 0;
		queue<int> nodes;
		string answer;
		answer.reserve(26);
		
		for (const auto & word : words) {
			for (char c : word)
				if (indegrees[c - 'a'] == -1)
					{
				indegrees[c - 'a'] = 0;
				uniq++;
			}
		}
		
		for (int i = 0; i < words.size() - 1; i++) {
			string first = words[i];
			string second = words[i + 1];
			
			int len1 = first.size(), len2 = second.size();
			int len = min(len1, len2);
			
			int j = 0;
			
			while (j < len && first[j] == second[j])
				j++;
			
			if (j == len && j < len1)
				return "";
			if (j < len) {adj[first[j] - 'a'].push_back(second[j] - 'a');
			indegrees[second[j] - 'a']++; }
		}
		
		for (int i = 0; i < 26; i++) {
			if (!indegrees[i])
				nodes.push(i);
		}
		
		while (!nodes.empty()) {
			auto node = nodes.front(); nodes.pop();
			
			answer.push_back(node + 'a');
			
			for (int child : adj[node]) {
				indegrees[child]--;
				if (!indegrees[child])
					nodes.push(child);
			}
		}
		
		return answer.size() == uniq ? answer : "";
	}
};
