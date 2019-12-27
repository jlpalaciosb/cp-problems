#include <iostream>
#include <vector>
#define INF 1000000000000
using namespace std;
typedef long long ll;

class SegmentTree {
private:
	vector<ll> st, lp; int n;
	int left (int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }
	void build(const vector<int> &A, int p, int L, int R) {
		if (L == R) st[p] = A[L];
		else {
			int mid = (L + R) >> 1;
			build(A, left(p) , L , mid);
			build(A, right(p), mid + 1, R );
			st[p] = min(st[left(p)], st[right(p)]);
		}
	}
	ll rmq(int p, int L, int R, int i, int j) {
		if (lp[p] != 0) {
			st[p] += lp[p];
			if (L != R) {
				lp[left(p)] += lp[p];
				lp[right(p)] += lp[p];
			}
			lp[p] = 0;
		}

		if (i > R || j < L) {
			return INF;
		} else if (i <= L && R <= j) {
			return st[p];
		} else {
			int mid = (L + R) >> 1;
			ll m1 = rmq(left(p), L, mid, i, j);
			ll m2 = rmq(right(p), mid + 1, R , i, j);
			return min(m1, m2);
		}
	}
	void inc(int p, int L, int R, int i, int j, int v) {
		if (lp[p] != 0) {
			st[p] += lp[p];
			if (L != R) {
				lp[left(p)] += lp[p];
				lp[right(p)] += lp[p];
			}
			lp[p] = 0;
		}

		if (j < L || i > R) {
			return;
		} else if (i <= L && R <= j) {
			st[p] += v;
			if (L != R) {
				lp[left(p)] += v;
				lp[right(p)] += v;
			}
		} else {
			int mid = (L + R) >> 1;
			inc(left(p), L, mid, i, j, v);
			inc(right(p), mid + 1, R, i, j, v);
			st[p] = min(st[left(p)], st[right(p)]);
		} 
	}
public:
	SegmentTree(const vector<int> &A) {
		n = A.size();
		st.assign(4 * n, 0);
		lp.assign(4 * n, 0);
		build(A, 1, 0, n - 1);
	}
	ll rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
	void inc(int i, int j, int v) { inc(1, 0, n - 1, i, j, v); }
};

int main() {
	int n; cin >> n;
	vector<int> a; a.resize(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	SegmentTree st(a);
	int m; cin >> m;
	for (int i = 0; i < m; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		if (getchar() == ' ') {
			int v; scanf("%d", &v);
			if (y < x) {
				st.inc(x, n - 1, v);
				st.inc(0, y, v);
			} else st.inc(x, y, v);
		} else {
			ll mm;
			if (y < x) mm = min(st.rmq(x, n - 1), st.rmq(0, y));
			else mm = st.rmq(x, y);
			printf("%lld\n", mm);
		}
	}
	return 0;
}
