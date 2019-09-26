#include <iostream>
using namespace std;

int main() {
	int a[200000], n, g, l, r;

	cin >> n;
	cin >> a[0];
	g = a[0]; l = -1; r = 1;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		if (a[i] > g) {
			g = a[i];
			l = i - 1;
			r = i + 1;
		}
	}

	bool possible = true;
	while (possible && (l > -1 || r < n)) {
		if (l > -1 && a[l] == g - 1) {
			g--;
			l--;
		} else if (r < n && a[r] == g - 1) {
			g--;
			r++;
		} else {
			possible = false;
		}
	}

	if (possible) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
