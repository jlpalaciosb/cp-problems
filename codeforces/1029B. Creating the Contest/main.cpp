#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	vi a(n), b(n); // b is dp
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	b[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (a[i + 1] <= 2 * a[i]) {
			b[i] = b[i + 1] + 1;
		} else {
			b[i] = 1;
		}
	}

	int ans = b[0];
	for (int i = 1; i < n; i++) {
		ans = max(ans, b[i]);
	}
	cout << ans << endl;

	return 0;
}
