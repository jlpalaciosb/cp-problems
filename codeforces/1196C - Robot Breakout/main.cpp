#include <iostream>
using namespace std;

class Region {
public:
	bool is_empty;
	int x1, y1; // left-bottom
	int x2, y2; // right-up

	Region() {
		x1 = y1 = -100000;
		x2 = y2 = 100000;
		is_empty = false;
	}

	Region(int x, int y, bool f1, bool f2, bool f3, bool f4) {
		x1 = x2 = x;
		y1 = y2 = y;
		if (f1) x1 = -100000;
		if (f2) y2 = 100000;
		if (f3) x2 = 100000;
		if (f4) y1 = -100000;
		is_empty = false;
	}

	Region intersect(Region rb) {
		Region ra = *this;
		Region res = Region();
		int x1, x2; // intersección en x
		int y1, y2; // intersección en y

		if (ra.is_empty || rb.is_empty) {
			res.is_empty = true;
			return res;
		}

		x1 = max(ra.x1, rb.x1);
		x2 = min(ra.x2, rb.x2);
		if (x2 < x1) {
			res.is_empty = true;
			return res;
		}

		y1 = max(ra.y1, rb.y1);
		y2 = min(ra.y2, rb.y2);
		if (y2 < y1) {
			res.is_empty = true;
			return res;
		}

		res.x1 = x1; res.y1 = y1;
		res.x2 = x2; res.y2 = y2;
		return res;
	}
};

int main() {
	int q, n, x, y;
	bool f1, f2, f3, f4;
	Region res, ri;

	cin >> q;
	while (q--) {
		cin >> n;
		res = Region();
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> f1 >> f2 >> f3 >> f4;
			ri = Region(x, y, f1, f2, f3, f4);
			res = res.intersect(ri);
		}
		if (res.is_empty) cout << 0 << endl;
		else cout << 1 << ' ' << res.x1 << ' ' << res.y1 << endl;
	}

	return 0;
}
