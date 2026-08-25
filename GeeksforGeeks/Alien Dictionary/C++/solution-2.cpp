class Solution {
	public:
	string findOrder(vector<string> &words) {
		// code here
		int size = words.size();
		vector<vector<int>> adj(26);
		vector<int> inDegrees(26, -1);
		string result;
		
		for (const auto & word : words) {
			for (const char c : word)
				inDegrees[c - 'a'] = 0;
		}
		
		for (int i = 0; i < (size - 1); i++) {
			const string & first = words[i];
			const string & second = words[i + 1];
			
			int size1 = first.size(), size2 = second.size();
			int len = min(size1, size2);
			
			int j = 0;
			while (j < len && first[j] == second[j]) {
				j++;
			}
			
			if (j < size1 && j == size2)
				return "";
			
			if (j < len) {
				adj[first[j] - 'a'].push_back(second[j] - 'a');
				inDegrees[second[j] - 'a']++;
			}
		}
		
		queue<int> nodes;
		int uniqChars = 0;
		
		for (int i = 0; i < 26; i++) {
			if (inDegrees[i] != -1) {
				uniqChars++;
				if (!inDegrees[i])
					nodes.push(i);
			}
		}
		
		result.reserve(uniqChars);
		
		while (!nodes.empty()) {
			int ch = nodes.front(); nodes.pop();
			result.push_back(ch + 'a');
			
			for (int c : adj[ch]) {
				inDegrees[c]--;
				if (!inDegrees[c])
					nodes.push(c);
			}
		}
		
		if (result.size() < uniqChars)
			return "";
		
		return result;
	}
};
