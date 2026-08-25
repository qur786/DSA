class Solution {
	public:
	string findOrder(vector<string> &words) {
		// code here
		int size = words.size();
		vector<vector<int>> adj(26);
		unordered_set<char> charSet;
		
		for (const auto & word : words) {
			for (const char c : word)
				charSet.insert(c);
		}
		
		string first = words[0];
		for (int i = 1; i < size; i++) {
			string second = words[i];
			
			int size1 = first.size(), size2 = second.size();
			int j = 0, k = 0;
			
			for (; j < size1 && k < size2 && first[j] == second[k]; j++, k++) {
			}
			
			if (j == size1) {
				first = second;
				continue;
			}
			if (k == size2)
				return "";
			
			adj[first[j] - 'a'].push_back(second[k] - 'a');
			
			first = second;
		}
		
		vector<int> inDegrees(26, 0);
		string result;
		
		for (int i = 0; i < adj.size(); i++) {
			for (int c : adj[i])
				inDegrees[c]++;
		}
		
		queue<int> nodes;
		
		for (int i = 0; i < 26; i++)
			if (charSet.count(i + 'a') && !inDegrees[i])
				nodes.push(i);
		
		while (!nodes.empty()) {
			int ch = nodes.front(); nodes.pop();
			result.push_back(ch + 'a');
			
			for (int c : adj[ch]) {
				inDegrees[c]--;
				if (!inDegrees[c])
					nodes.push(c);
			}
		}
		
		if (result.size() != charSet.size())
			return "";
		
		return result;
	}
};
