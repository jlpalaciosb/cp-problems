#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<ll> a(300000), b(300000), c(300000);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}
		ll sum = c[0] = max(0ll, a[0] - b[n - 1]);
		for (int i = 1; i < n; i++) {
			c[i] = max(0ll, a[i] - b[i - 1]);
			sum += c[i];
		}
		ll ans = sum - c[0] + a[0];
		for (int i = 1; i < n; i++) {
			ans = min(ans, sum - c[i] + a[i]);
		}
		cout << ans << endl;
	}

	return 0;
}
