class Solution {
	private:
	int count = 0;
	public:
	int towerOfHanoi(int n, int from, int to, int aux) {
		if (n == 0)
			return 0;
		
		towerOfHanoi(n - 1, from, aux, to);
		towerOfHanoi(n - 1, aux, to, from);
		count += 1;
		
		return count;
	}
};
