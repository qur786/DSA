class Solution {
	private:
	int getFib(int n, vector<int> & fib) {
		if (n == 0)
			return fib[0];
		if (n == 1)
			return fib[1];
		
		if (fib[n] == -1)
			fib[n] = getFib(n - 1, fib) + getFib(n - 2, fib);
		
		return fib[n];
	}
	public:
	int nthFibonacci(int n) {
		vector<int> fib(n + 1, -1);
		fib[0] = 0;
		fib[1] = 1;
		return getFib(n, fib);
	}
};
