#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

class segment { public:
	int l, r;
	segment(int l_, int r_) {
		l = l_;
		r = r_;
	}
};
class compare { public:
	bool operator()(segment s1, segment s2) {
		int l1 = s1.r - s1.l + 1;
		int l2 = s2.r - s2.l + 1;
		if (l1 != l2) {
			return l1 < l2;
		} else {
			return s1.l > s2.l;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vi a; a.reserve(200000);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		a.resize(n);

		int i = 1;
		priority_queue<segment, vector<segment>, compare> pq;
		pq.push(segment(0, n - 1));
		while (!pq.empty()) {
			segment s = pq.top(); pq.pop();
			int len = s.r - s.l + 1;
			if (len == 1) {
				a[s.l] = i++;
			} else if (len == 2) {
				a[s.l] = i++;
				pq.push(segment(s.r, s.r));
			} else {
				int mid = (s.l + s.r) / 2;
				a[mid] = i++;
				pq.push(segment(s.l, mid - 1));
				pq.push(segment(mid + 1, s.r));
			}
		}

		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}

	return 0;
}
