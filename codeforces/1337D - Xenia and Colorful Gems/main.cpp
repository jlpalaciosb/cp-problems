#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vi::iterator viit;

ll solve(vi &x, vi &y, vi &z) {
	ll r = 9e18;
	for (int i = 0; i < y.size(); i++) {
		int yi = y[i];
		viit it1 = lower_bound(x.begin(), x.end(), yi);
		viit it2 = lower_bound(z.begin(), z.end(), yi);
		if (it1 == x.end()) {
			it1--;
		} else if (it1 == x.begin()) {
			if (*it1 > yi) {
				continue;
			}
		} else if (*it1 > yi) {
			it1--;
		}
		if (it2 == z.end()) {
			continue;
		}
		int xi = *it1;
		int zi = *it2;
		ll d1 = xi - yi, d2 = xi - zi, d3 = yi - zi;
		r = min(r, d1 * d1 + d2 * d2 + d3 * d3);
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vi r, g, b; r.reserve(100000); g.reserve(100000); b.reserve(100000);

	int t; cin >> t;
	while (t--) {
		int nr, ng, nb; cin >> nr >> ng >> nb;
		r.resize(nr); g.resize(ng); b.resize(nb);
		for (int i = 0; i < nr; i++) {
			cin >> r[i];
		}
		for (int i = 0; i < ng; i++) {
			cin >> g[i];
		}
		for (int i = 0; i < nb; i++) {
			cin >> b[i];
		}
		sort(r.begin(), r.end());
		sort(g.begin(), g.end());
		sort(b.begin(), b.end());
		ll ans = 9e18;
		ans = min(ans, solve(r, g, b));
		ans = min(ans, solve(r, b, g));
		ans = min(ans, solve(g, r, b));
		ans = min(ans, solve(g, b, r));
		ans = min(ans, solve(b, r, g));
		ans = min(ans, solve(b, g, r));
		cout << ans << endl;
	}

	return 0;
}
