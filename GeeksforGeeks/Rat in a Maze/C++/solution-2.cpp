class Solution {
	private:
	static constexpr int rowD[4] = {1, 0, 0, -1};
	static constexpr int colD[4] = {0, -1, 1, 0};
	static constexpr int dirs[4] = {'D', 'L', 'R', 'U'};
	vector<string> answer;
	string comb;
	
	void solve(vector<vector<int>> & maze, int x, int y, int n) {
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
				solve(maze, adjX, adjY, n);
				maze[adjX][adjY] = 1;
				comb.pop_back();
			}
		}
	}
	public:
	vector<string> ratInMaze(vector<vector<int>> & maze) {
		int n = maze.size();
		if (!maze[0][0] || !maze[n - 1][n - 1])
			return {};
		maze[0][0] = 0;
		solve(maze, 0, 0, n);
		
		return answer;
	}
};
