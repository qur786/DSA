class Solution {
	public:
	string findOrder(vector<string> &words) {
		// code here
		int size = words.size();
		vector<int> inDegrees(26, -1);
		vector<vector<int>> adj(26);
		string answer;
		answer.reserve(26);
		int uniqChars = 0;
		
		for (const string & word : words) {
			for (const char ch : word)
				if (inDegrees[ch - 'a'] == -1)
					{inDegrees[ch - 'a'] = 0; uniqChars++; }
		}
		
		for (int i = 0; i < size - 1; i++) {
			string first = words[i];
			string second = words[i + 1];
			
			int len1 = first.size(), len2 = second.size();
			int len = min(len1, len2);
			int j = 0;
			while (j < len && first[j] == second[j])
				j++;
			
			if (j == len && len == len2)
				return "";
			if (j < len) {
				adj[first[j] - 'a'].push_back(second[j] - 'a');
				inDegrees[second[j] - 'a']++;
			}
		}
		
		queue<int> nodes;
		
		for (int i = 0; i < 26; i++) if (inDegrees[i] == 0)
			nodes.push(i);
		
		while (!nodes.empty()) {
			int front = nodes.front();
			nodes.pop();
			answer.push_back(front + 'a');
			
			for (int neighbor : adj[front]) {
				inDegrees[neighbor]--;
				if (!inDegrees[neighbor])
					nodes.push(neighbor);
			}
		}
		
		return answer.size() == uniqChars ? answer : "";
	}
};
