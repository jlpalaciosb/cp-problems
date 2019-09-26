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
	// int cum[4] = {0, 1, 3, 6};
	// int b = upper_bound(cum, cum + 4, 6) - cum;
	// cout << b << endl;
	for (int i = 1; i <= 10; i++) {
		int n; cin >> n;
		cout << dig(n) << endl;
	}
	return 0;
}
