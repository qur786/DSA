#include <iostream>
using namespace std;

void print(int n) {
	if (n == 0)
		return;
	
	cout << "GFG ";
	print(n - 1);
}

int main() {
	int n;
	cin>> n;
	
	// code here
	print(n);
	
	return 0;
}
