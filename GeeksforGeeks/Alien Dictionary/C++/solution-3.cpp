class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        vector<int> inDegrees(26, -1);
        int uniqChars = 0;
        
        for (const string & word : words)
            for (const char & ch : word) if (inDegrees[ch - 'a'] == -1) {uniqChars++; inDegrees[ch - 'a'] = 0;}
            
        vector<vector<int>> adj(26);
        int wordCount = words.size();
        
        for (int i = 0; i < (wordCount - 1); i++) {
            const string & first = words[i];
            const string & second = words[i + 1];
            
            int j = 0;
            int len1 = first.size(), len2 = second.size();
            int len = min(len1, len2);
            
            while (j < len) {
                if (first[j] != second[j]) {
                    adj[first[j] - 'a'].push_back(second[j] - 'a');
                    inDegrees[second[j] - 'a']++;
                    break;
                }
                j++;
            }
            
            if (j == len && j < len1) return "";
        }
        
        queue<int> nodes;
        string answer;
        answer.reserve(uniqChars);
        
        for (int i = 0; i < 26; i++) if (!inDegrees[i]) nodes.push(i);
        
        while (!nodes.empty()) {
            int front = nodes.front(); nodes.pop();
            answer.push_back(front + 'a');
            
            for (int n : adj[front]) {
                inDegrees[n]--;
                if (!inDegrees[n]) nodes.push(n);
            }
        }
    
        
        return answer.size() == uniqChars ? answer : "";
    }
};