#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

vi a, k; int n, q;

int count_le(int x) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] <= x) {
			cnt++;
		}
	}
	for (int i = 0; i < q; i++) {
		int ki = k[i];
		if (ki > 0 && ki <= x) {
			cnt++;
		} else if (ki < 0 && abs(ki) <= cnt) {
			cnt--;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	a.resize(n); k.resize(q);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> k[i];
	}

	if (count_le(n) == 0) {
		cout << 0 << endl;
	} else {
		int l = 1, r = n;
		while (r > l) {
			int m = (r + l) / 2;
			if (count_le(m) == 0) {
				l = m + 1;
			} else {
				r = m;
			}
		}
		cout << r << endl;
	}

	return 0;
}
