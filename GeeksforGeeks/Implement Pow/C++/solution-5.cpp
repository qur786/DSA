class Solution {
	public:
	double power(double b, int e) {
		// code here
		if (b == 1)
			return 1;
		if (e == 0)
			return 1;
		if (b == 0)
			return 0;
		if (e == 1)
			return b;
		if (e < 0)
			return power(1/b, -e);
		
		long long i = 2;
		double result = 1, value = b;
		
		while (i <= e) {
			
			while (i <= e) {
				value *= value;
				i *= 2;
			}
			result *= value;
			e = e - i / 2;
			i = 2;
			value = b;
		}
		
		if (e == 1)
			result *= b;
		
		return result;
	}
};
