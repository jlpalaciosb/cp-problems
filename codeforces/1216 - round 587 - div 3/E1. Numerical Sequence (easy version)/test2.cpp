#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

char buffer[33];
int dig(int n, int i) {
	sprintf(buffer, "%d", n);
	return buffer[i] - '0';
}

int dig(int i) {
	if (i <= 9)
		return i;
	if (i <= 189)
		return dig(10 + (i - 1 - 9) / 2, (i - 1 - 9) % 2);
	if (i <= 2889)
		return dig(100 + (i - 1 - 189) / 3, (i - 1 - 189) % 3);
	if (i <= 38889)
		return dig(1000 + (i - 1 - 2889) / 4, (i - 1 - 2889) % 4);
	if (i <= 488889)
		return dig(10000 + (i - 1 - 38889) / 5, (i - 1 - 38889) % 5);
	if (i <= 5888889)
		return dig(100000 + (i - 1 - 488889) / 6, (i - 1 - 488889) % 6);
	return -1;
}

int main() {
	for (int i = 1; i <= 10000; i++) {
		cout << dig(i);
	}
	return 0;
}
