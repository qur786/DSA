class Solution {
	public:
	double power(double b, int e) {
		// code here
		if (b == 0)
			return 0;
		if (b == 1)
			return 1;
		if (e == 0)
			return 1;
		if (e == 1)
			return b;
		if (e < 0)
			return power(1/b, -e);
		
		double ans = 1, p = 2, value = b;
		
		while (p <= e) {
			while (p <= e) {
				p *= 2;
				value *= value;
			}
			
			e = e - p / 2;
			ans *= value;
			value = b;
			p = 2;
		}
		
		if (e > 0)
			ans *= b;
		
		return ans;
	}
};
