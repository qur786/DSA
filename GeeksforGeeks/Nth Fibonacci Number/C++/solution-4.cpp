class Solution {
	public:
	int nthFibonacci(int n) {
		int fib1 = 0, fib2 = 1, fib3 = 0;
		if (n == 0)
			return fib1;
		if (n == 1)
			return fib2;
		
		for (int i = 2; i <= n; i++) {
			fib3 = fib1 + fib2;
			fib1 = fib2;
			fib2 = fib3;
		}
		
		return fib3;
	}
};
