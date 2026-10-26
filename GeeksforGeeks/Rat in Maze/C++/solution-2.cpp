class Solution {
	private:
	static constexpr int rowD[4] = {1, 0, 0, -1};
	static constexpr int colD[4] = {0, -1, 1, -0};
	static constexpr char dirs[4] = {'D', 'L', 'R', 'U'};
	void solve(vector<vector<int>> & maze, vector<string> & answer, string & comb, int n, int x, int y) {
		if (x == n - 1 && y == n - 1) {
			answer.push_back(comb);
			return;
		}
		
		for (int d = 0; d < 4; d++) {
			int adjX = x + rowD[d];
			int adjY = y + colD[d];
			
			if (0 <= adjX && adjX < n && 0 <= adjY && adjY < n && maze[adjX][adjY]) {
				maze[adjX][adjY] = 0;
				comb.push_back(dirs[d]);
				solve(maze, answer, comb, n, adjX, adjY);
				comb.pop_back();
				maze[adjX][adjY] = 1;
			}
		}
	}
	public:
	vector<string> ratInMaze(vector<vector<int>> & maze) {
		// code here
		int n = maze.size();
		if (!maze[0][0] || !maze[n - 1][n - 1])
			return {};
		vector<string> answer;
		string comb;
		
		maze[0][0] = 0;
		
		solve(maze, answer, comb, n, 0, 0);
		
		return answer;
	}
};
