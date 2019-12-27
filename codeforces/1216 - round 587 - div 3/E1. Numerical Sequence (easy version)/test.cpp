#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

int ndig(int n) {
	return floor(log(n) / log(10)) + 1;
}

int main() {
	cout << ndig(50000) << endl;
	return 0;
}
