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
		int a, b, c, d; cin >> a >> b >> c >> d;
		int x, y, x1, y1, x2, y2; cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		bool ans = true;

		if (x1 == x2) {
			if (a > 0 || b > 0) ans = false;
		} else {
			if (a > b) {
				if (a - b > x - x1) ans = false;
			} else if (b > a) {
				if (b - a > x2 - x) ans = false;
			}
		}

		if (y1 == y2) {
			if (c > 0 || d > 0) ans = false;
		} else {
			if (c > d) {
				if (c - d > y - y1) ans = false;
			} else if (d > c) {
				if (d - c > y2 - y) ans = false;
			}
		}

		cout << (ans ? "YES" : "NO") << endl;
	}

	return 0;
}
