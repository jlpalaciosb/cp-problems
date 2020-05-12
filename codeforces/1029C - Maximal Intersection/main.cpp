#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

class segment { public:
	bool empty = false;
	int l, r;
	segment() { // default constructor
		l = r = 0;
	}
	segment(int l_, int r_) {
		l = l_;
		r = r_;
		if (l > r) empty = true;
	}
	int length() {
		if (empty) return 0;
		else return r - l;
	}
	segment intersection(segment s) {
		if (empty || s.empty) {
			return segment(1, 0);
		} else {
			return segment(max(l, s.l), min(r, s.r));
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<segment> vs(n);
	for (int i = 0; i < n; i++) {
		cin >> vs[i].l >> vs[i].r;
	}

	vector<segment> pi(n);
	pi[0] = vs[0];
	for (int i = 1; i < n; i++) {
		pi[i] = pi[i - 1].intersection(vs[i]);
	}

	vector<segment> si(n);
	si[n - 1] = vs[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		si[i] = si[i + 1].intersection(vs[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			ans = max(ans, si[1].length());
		} else if (i == n - 1) {
			ans = max(ans, pi[n - 2].length());
		} else {
			ans = max(ans, pi[i - 1].intersection(si[i + 1]).length());
		}
	}
	cout << ans << endl;

	return 0;
}
