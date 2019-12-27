#include <iostream>
#include <stdio.h>
#include <float.h>

using namespace std;

int main() {
	long long int n = 8; // size = 8 = sizeof(long), you can use long double that has a size of 16 bytes
	cout << sizeof(n) << endl;

	long double a = LDBL_MAX;

	cout << (a == a - 1) << endl << endl;
	
	printf("%.0Lf\n\n", a);

	a = a - 1;
	printf("%.0Lf\n\n", a);

	return 0;
}
