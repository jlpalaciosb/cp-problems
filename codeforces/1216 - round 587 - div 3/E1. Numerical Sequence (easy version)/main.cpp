#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

int ndigb[50010]; // numero de digitos del bloque i
ll cum[50010]; // numero de digitos en la secuencia al agregar el bloque i

// numero de digitos de n
int ndig(int n) {
	return floor(log(n) / log(10)) + 1;
}

// digito en la posicion i de n, dig(8391, 2) = 9
char buffer[33];
int dig(int n, int i) {
	sprintf(buffer, "%d", n);
	return buffer[i] - '0';
}

// digito en la posicion i de 123456789101112...
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

int solve(int k) {
	int b = upper_bound(cum, cum + 50001, k) - cum;
	if (cum[b - 1] == k) b = b - 1;
	return dig(k - cum[b - 1]);
}

int main() {
	ndigb[0] = cum[0] = 0;
	for (int i = 1; i <= 50000; ++i) {
		ndigb[i] = ndigb[i - 1] + ndig(i);
		cum[i] = cum[i - 1] + ndigb[i];
	}

	int q; cin >> q;
	while (q--) {
		int k; cin >> k;
		cout << solve(k) << endl;
	}

	return 0;
}
