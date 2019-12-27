#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;

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

int main() {
	ll k; cin >> k;
	cout << kth_digit(k) << endl;
	return 0;
}
