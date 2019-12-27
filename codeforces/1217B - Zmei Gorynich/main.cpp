#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n, x; cin >> n >> x;
		int rmax = 0, rd, dmax = 0;
		for (int i = 0; i < n; ++i) {
			int d, h; cin >> d >> h;
			int r = d - h;
			if (d > dmax) dmax = d;
			if (r > rmax) {
				rmax = r;
				rd = d;
			}
		}

		if (rmax == 0) {
			if (dmax >= x) cout << 1 << endl;
			else cout << -1 << endl;
		} else {
			int bx = x - dmax;
			if (bx <= 0) {
				cout << 1 << endl;
			} else {
				int bc = ceil((double)bx / (double)rmax);
				if (x - (bc - 2) * rmax - rd <= 0)
					cout << bc - 1 << endl;
				else if (x - (bc - 1) * rmax - rd <= 0)
					cout << bc << endl;
				else
					cout << bc + 1 << endl;
			}
		}
	}
	return 0;
}
