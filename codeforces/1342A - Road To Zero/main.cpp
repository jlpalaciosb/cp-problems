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
		ll x, y, a, b; cin >> x >> y >> a >> b;
		if (2 * a < b) {
			b = 2 * a;
		}
		ll ans = min(x, y) * b + abs(x - y) * a;
		cout << ans << endl;
	}

	return 0;
}
