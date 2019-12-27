#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

ll p[40], cum[40];



int main() {
	p[0] = 1; cum[0] = 1;
	for (ll i = 1; i <= 38; ++i) {
		p[i] = pow(3, i);
		cum[i] = p[i] + cum[i - 1];
	}

	int q; cin >> q;
	while (q--) {
		ll n; cin >> n;
		ll sum = 0, t = n;
		int i = 38;
		while (sum < n) {
			if (i == 0) {
				sum += 1;
			} else if (cum[i - 1] < t) {
				sum += p[i];
				t -= p[i];
			}
			i--;
		}
		cout << sum << endl;
	}
	return 0;
}
