class Solution {
	private:
	const int rowD[4] = {1, 0, 0, -1};
	const int colD[4] = {0, -1, 1, 0};
	const char dirs[4] = { 'D', 'L', 'R', 'U'};
	vector<string> answer;
	string comb;
	void rat(vector<vector<int>> & maze, int x, int y, int rows, int cols, vector<vector<bool>> & visited) {
		if (x == rows - 1 && y == cols - 1) {
			answer.push_back(comb);
			return;
		}
		
		for (int d = 0; d < 4; d++) {
			int adjX = x + rowD[d];
			int adjY = y + colD[d];
			
			if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols && maze[adjX][adjY] && !visited[adjX][adjY]) {
				visited[adjX][adjY] = true;
				comb.push_back(dirs[d]);
				rat(maze, adjX, adjY, rows, cols, visited);
				comb.pop_back();
				visited[adjX][adjY] = false;
			}
		}
	}
	
	public:
	vector<string> ratInMaze(vector<vector<int>> & maze) {
		// code here
		if (!maze[0][0])
			return {};
		int rows = maze.size(), cols = maze[0].size();
		vector<vector<bool>> visited(rows, vector<bool>(cols, false));
		visited[0][0] = true;
		
		rat(maze, 0, 0, rows, cols, visited);
		
		return answer;
	}
};
