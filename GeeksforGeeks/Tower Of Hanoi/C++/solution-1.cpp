class Solution {
	private: int count = 0;
	public:
	int towerOfHanoi(int n, int from, int to, int aux) {
		if (n == 0)
			return this -> count;
		this -> count++;
		towerOfHanoi(n - 1, from, aux, to);
		towerOfHanoi(n - 1, aux, to, from);
		
		return this -> count;
	}
};
