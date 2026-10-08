class Solution {
	public:
	double power(double b, int e) {
		// code here
		if (e == 0)
			return 1;
		if (e == 1)
			return b;
		if (b == 0)
			return 0;
		if (b == 1)
			return 1;
		if (e < 0)
			return power(1/b, -e);
		
		double value = 1;
		double temp = b, p = 2;
		
		while (p <= e) {
			
			while (p <= e) {
				temp *= temp;
				p *= 2;
			}
			value *= temp;
			e = e - p /2;
			temp = b;
			p = 2;
		}
		
		if (e > 0)
			value *= b;
		
		return value;
	}
};
