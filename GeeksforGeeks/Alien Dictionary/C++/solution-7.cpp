class Solution {
	public:
	string findOrder(vector<string> &words) {
		// code here
		vector<int> indegrees(26, -1);
		int uniq = 0;
		string result;
		
		for (int i = 0; i < words.size(); i++) {
			for (char c : words[i]) {
				if (indegrees[c - 'a'] == -1) {
					uniq++;
					indegrees[c - 'a'] = 0;
				}
			}
		}
		
		vector<vector<int>> adj(26);
		
		for (int i = 1; i < words.size(); i++) {
			string str1 = words[i - 1];
			string str2 = words[i];
			
			int len1 = str1.size(), len2 = str2.size();
			
			int len = min(len1, len2);
			int j = 0;
			while (j < len && str1[j] == str2[j])
				j++;
			
			if (j == len && len1 > j)
				return "";
			if (j < len) {
				adj[str1[j] - 'a'].push_back(str2[j] - 'a');
				indegrees[str2[j] - 'a']++;
			}
		}
		
		queue<int> nodes;
		
		for (int i = 0; i < 26; i++) {
			if (!indegrees[i])
				nodes.push(i);
		}
		
		while (!nodes.empty()) {
			auto front = nodes.front(); nodes.pop();
			result.push_back(front + 'a');
			
			for (int child : adj[front]) {
				indegrees[child]--;
				if (!indegrees[child])
					nodes.push(child);
			}
		}
		
		return result.size() == uniq ? result : "";
	}
};
