#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		ll n, d, x[1000];
		cin >> n >> d;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		for (int i = n - 1; i >= 0; i--) {
			d = d - d % x[i];
		}
		printf("Case #%d: %lld\n", t, d);
	}

	return 0;
}
