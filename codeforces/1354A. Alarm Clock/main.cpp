#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		ll a, b, c, d; cin >> a >> b >> c >> d;
		if (b >= a) {
			cout << b << endl;
		} else if (c <= d) {
			cout << -1 << endl;
		} else {
			ll r = a - b;
			ll e = c - d;
			ll f = r / e;
			if (e * f < r) f++;
			cout << (b + f * c) << endl;
		}
	}

	return 0;
}
