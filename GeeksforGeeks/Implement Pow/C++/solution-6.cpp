class Solution {
	public:
	double power(double b, int e) {
		if (b == 0)
			return 0;
		if (b == 1)
			return 1;
		if (e == 0)
			return 1;
		if (e < 0)
			return power(1/b, -e);
		
		double result = 1;
		double value = b;
		long long i = 2;
		
		while (i <= e) {
			while (i <= e) {
				value *= value;
				i *= 2;
			}
			
			result *= value;
			value = b;
			e = e - i / 2;
			i = 2;
		}
		
		if (e == 1)
			result *= b;
		
		return result;
	}
};
