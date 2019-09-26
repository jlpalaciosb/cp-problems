#include <iostream>
#include <algorithm>
using namespace std;

int q, n, s[400];

int main() {
	cin >> q;
	while (q--) {
		cin >> n;
		for (int i = 0; i < 4 * n; i++) cin >> s[i];
		sort(s, s + 4 * n);

		int c = 0;
		for (int i = 0; i < 4 * n; i += 2) {
			if (s[i] != s[i + 1]) {
				cout << "NO" << endl;
				break;
			}
			s[c++] = s[i];
		}
		if (c != 2 * n) continue;

		int area = s[0] * s[2 * n - 1], i;
		for (i = 0; i < n; i++) {
			if (s[i] * s[2 * n - i - 1] != area) {
				cout << "NO" << endl;
				break;
			}
		}
		if (i == n) cout << "YES" << endl;
	}
	return 0;
}
