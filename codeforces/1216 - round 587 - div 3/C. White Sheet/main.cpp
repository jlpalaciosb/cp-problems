#include <iostream>
using namespace std;
typedef long long ll;

class region {
public:
	int x1, y1, x2, y2;
	bool empty;
	region() { // empty region
		empty = true;
	}
	region(int x1_, int y1_, int x2_, int y2_) {
		x1 = x1_;
		y1 = y1_;
		x2 = x2_;
		y2 = y2_;
		empty = false;
	}
	ll surf() {
		if (empty) return 0;
		else return (ll)(x2 - x1) * (ll)(y2 - y1);
	}
	region intersec(region r) {
		if (empty || r.empty) return region();
		int x1_ = max(x1, r.x1);
		int x2_ = min(x2, r.x2);
		if (x2_ < x1_) return region();
		int y1_ = max(y1, r.y1);
		int y2_ = min(y2, r.y2);
		if (y2_ < y1_) return region();
		return region(x1_, y1_, x2_, y2_);
	}
};

int main() {
	int x1, y1, x2, y2;

	cin >> x1 >> y1 >> x2 >> y2;
	region r1 = region(x1, y1, x2, y2);

	cin >> x1 >> y1 >> x2 >> y2;
	region r2 = region(x1, y1, x2, y2);

	cin >> x1 >> y1 >> x2 >> y2;
	region r3 = region(x1, y1, x2, y2);

	region ra = r1.intersec(r2);
	region rb = r1.intersec(r3);
	region rc = ra.intersec(rb);

	if (ra.surf() + rb.surf() - rc.surf() == r1.surf())
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

	return 0;
}
