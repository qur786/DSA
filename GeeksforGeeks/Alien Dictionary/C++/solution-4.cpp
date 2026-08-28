class Solution {
	public:
	string findOrder(vector<string> &words) {
		int uniqueChars = 0;
		vector<int> inDegrees(26, -1);
		vector<vector<int>> adj(26);
		queue<int> nodes;
		string answer;
		answer.reserve(26);
		
		for (const auto & word : words) {
			for (const auto & ch : word) {
				if (inDegrees[ch - 'a'] == -1) {
					inDegrees[ch - 'a'] = 0;
					uniqueChars++;
				}
			}
		}
		
		int wordCount = words.size();
		
		for (int i = 0; i < (wordCount - 1); i++) {
			const auto & first = words[i];
			const auto & second = words[i + 1];
			
			int len1 = first.size(), len2 = second.size();
			int len = min(len1, len2);
			
			int j = 0;
			
			while (j < len && first[j] == second[j]) { j++; }
			
			if (j == len && j < len1)
				return "";
			
			if (j < len)
				{ adj[first[j] - 'a'].push_back(second[j] - 'a');
			inDegrees[second[j] - 'a']++; }
		}
		
		for (int i = 0; i < 26; i++) {
			if (!inDegrees[i])
				nodes.push(i);
		}
		
		while (!nodes.empty()) {
			int front = nodes.front(); nodes.pop();
			answer.push_back(front + 'a');
			
			for (int child : adj[front]) {
				inDegrees[child]--;
				if (!inDegrees[child])
					nodes.push(child);
			}
		}
		
		return answer.size() == uniqueChars ? answer : "";
	}
};
