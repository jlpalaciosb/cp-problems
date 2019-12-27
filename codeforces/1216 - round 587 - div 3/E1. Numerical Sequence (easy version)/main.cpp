#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
typedef long double ld;

int ndigb[25000]; // numero de digitos del bloque i
int cum[25000]; // numero de digitos en la secuencia al agregar el bloque i
int NB;

// numero de digitos de n
int ndig(int n) {
	return floor(log(n) / log(10)) + 1;
}

char kth_digit(ll k) {
	ll len = 1, cum = 0;
	while (true) {
		ll first = powl(10, len - 1);
		ll c = 9 * (ll)powl(10, len - 1) * len;
		if (k <= cum + c) {
			ll n = first + ceil((ld)(k - cum) / (ld)len) - 1;
			int i = (k - cum - 1) % len;
			char buffer[50];
			sprintf(buffer, "%lld", n);
			return buffer[i];
		}
		cum += c;
		len++;
	}
}

char solve(int k) {
	int b = upper_bound(cum, cum + NB + 1, k) - cum;
	if (cum[b - 1] == k) b = b - 1;
	printf("* %d %d %d/%d\n", cum[b - 1], cum[b], b, NB);
	printf("* %d/%d\n", k - cum[b - 1], ndigb[b]);
	return kth_digit(k - cum[b - 1]);
}

int main() {
	ndigb[0] = cum[0] = 0;
	bool f = false;
	for (int i = 1; i < 25000; ++i) {
		ndigb[i] = ndigb[i - 1] + ndig(i);
		cum[i] = cum[i - 1] + ndigb[i];
		NB = i;
		if (cum[i] > 1000000000) break;
	}

	int q; cin >> q;
	while (q--) {
		int k; cin >> k;
		cout << solve(k) << endl;
	}

	return 0;
}
