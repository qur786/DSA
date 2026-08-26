class Solution {
	public:
	int nthFibonacci(int n) {
		int fib = 0;
		int fib1 = 0, fib2 = 1;
		if (n == 0)
			return fib1;
		if (n == 1)
			return fib2;
		
		for (int i = 2; i <= n; i++) {
			fib = fib1 + fib2;
			fib1 = fib2;
			fib2 = fib;
		}
		
		return fib;
	}
};
