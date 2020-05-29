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
		int n; cin >> n;
		if (n == 1) {
			cout << 0 << endl;
		} else {
			ll ans = 0;
			for (ll i = 3, j = 1; i <= n; i += 2, j++) {
				ans += (i * 2 + (i - 2) * 2) * j;
			}
			cout << ans << endl;
		}
	}

	return 0;
}
