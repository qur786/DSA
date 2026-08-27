class Solution {
	public:
	double power(double b, int e) {
		if (b == 1)
			return 1;
		if (e == 0)
			return 1;
		if (e < 0)
			return power(1/b, -e);
		
		double result = 1;
		long long i = 2;
		
		while (i <= e) {
			double value = b;
			while (i <= e) {
				value *= value;
				i *= 2;
			}
			result *= value;
			e = e - i/2;
			i = 2;
		}
		
		i = 1;
		
		while (i <= e) {
			result *= b;
			i++;
		}
		
		return result;
	}
};
