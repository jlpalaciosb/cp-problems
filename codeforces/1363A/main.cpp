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
		int n, x; cin >> n >> x;
		vi a(n);
		int ec = 0, oc = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] % 2 == 0) {
				ec++;
			} else {
				oc++;
			}
		}
		bool ans = false;
		for (int i = 1; i <= oc && i <= x; i += 2) {
			if (ec >= x - i) {
				ans = true;
			}
		}
		if (ans) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

	return 0;
}
