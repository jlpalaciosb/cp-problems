#include <iostream>
using namespace std;

int main() {
	int a[200001], q, k, n, oc;

	cin >> q;
	while (q--) {
		cin >> n >> k;

		oc = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] % 2 == 1) oc++;
		}

		if (oc >= k && (oc - (k - 1)) % 2 == 1) {
			cout << "YES" << endl;
			int c = 0;
			for (int i = 1; i <= n && c < k - 1; i++) {
				if (a[i] % 2 == 1) {
					cout << i << ' ';
					c++;
				}
			}
			cout << n << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
