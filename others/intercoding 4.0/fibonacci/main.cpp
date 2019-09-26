#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	vector<long double> v(100);
	v[0] = 0;
	v[1] = 1;
	for(int i = 2; i < 100; i++) {
		v[i] = v[i-1] + v[i-2];
	}
	for(int i = 0; i < 100; i++) {
		printf("%.0Lf\n", v[i]);
	}
	return 0;
}
