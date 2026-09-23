#include <iostream>
using namespace std;

int getSum(int n) {
	if (n == 0)
		return 0;
	
	return getSum(n - 1) + n;
}

int main() {
	int n;
	cin>> n;
	
	// code here
	int sum = getSum(n);
	
	cout << sum;
	
	return 0;
}
