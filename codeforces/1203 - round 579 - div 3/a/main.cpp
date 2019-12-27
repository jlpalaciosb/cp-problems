#include <iostream>
using namespace std;

int n, p[200];

int next(int i) {
	int nxt = i + 1;
	if (nxt == n) nxt = 0;
	return nxt;
}

int prev(int i) {
	int prv = i - 1;
	if (prv == -1) prv = n - 1;
	return prv;
}

int main() {
	int q; cin >> q;
	while (q--) {
		int oi, dir; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			if (p[i] == 1) oi = i;
		}

		if (n == 1) {
			cout << "YES" << endl;
			continue;
		}

		if (p[next(oi)] == 2) {
			dir = 1;
		} else {
			dir = -1;
		}

		for (int i = 1; i <= n; i++) {
			if (p[oi] != i) {
				cout << "NO" << endl;
				break;
			}
			if (i == n) cout << "YES" << endl;
			oi = (dir == 1 ? next(oi) : prev(oi));
		}
	}

	return 0;
}
