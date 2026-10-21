class Solution {
	public:
	void printTillN(int n) {
		if (n == 0)
			return;
		// code here
		printTillN(n - 1);
		
		cout << n << " ";
	}
};
