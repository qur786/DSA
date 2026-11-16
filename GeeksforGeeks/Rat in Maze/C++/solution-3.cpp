class Solution {
	private:
	static constexpr int rowD[4] = {1, 0, 0, -1};
	static constexpr int colD[4] = {0, -1, 1, 0};
	string dirs = "DLRU";
	void solve(vector<string> & answer, string & comb, vector<vector<int>> & maze, int i, int j, int rows, int cols) {
		if (i == rows - 1 && j == cols - 1) {
			answer.push_back(comb);
			return;
		}
		
		for (int d = 0; d < 4; d++) {
			int adjX = i + rowD[d];
			int adjY = j + colD[d];
			
			if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols && maze[adjX][adjY]) {
				comb.push_back(dirs[d]);
				maze[i][j] = 0;
				solve(answer, comb, maze, adjX, adjY, rows, cols);
				comb.pop_back();
				maze[i][j] = 1;
			}
		}
	}
	public:
	vector<string> ratInMaze(vector<vector<int>> & maze) {
		// code here
		int rows = maze.size(), cols = maze[0].size();
		if (rows == 0 && cols == 0)
			return {};
		if (maze[0][0] == 0 || maze[rows - 1][cols - 1] == 0)
			return {};
		
		vector<string> answer;
		string comb;
		maze[0][0] = 0;
		solve(answer, comb, maze, 0, 0, rows, cols);
		return answer;
	}
};
