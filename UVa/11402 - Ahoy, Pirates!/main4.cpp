#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

// error lazy update al invertir :c
class SegmentTree {
private:
	vi st;
	vi lazy_val, lazy_inv;
	int n;
	int left (int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }
	void build(const vi &A, int p, int L, int R) {
		if (L == R) {
			st[p] = A[L];
		} else {
			build(A, left(p) , L , (L + R) / 2);
			build(A, right(p), (L + R) / 2 + 1, R );
			st[p] = st[left(p)] + st[right(p)];
		}
	}
	int sum(int p, int L, int R, int i, int j) {
		if (i > R || j < L) return 0; // rango actual afuera

		if (lazy_val[p] != -1) {
			st[p] = lazy_val[p] * (R - L + 1);
			if (L != R) {
				lazy_val[left(p)] = lazy_val[right(p)] = lazy_val[p];
			}
			lazy_val[p] = -1;
		}

		if (lazy_inv[p] != 0) {
			if (lazy_inv[p] % 2 == 1) st[p] = (R - L + 1) - st[p];
			if (L != R) {
				lazy_inv[left(p)] += lazy_inv[p];
				lazy_inv[right(p)] += lazy_inv[p];
			}
		}

		if (i <= L && R <= j) return st[p]; // rango actual adentro

		int s1 = sum(left(p), L, (L + R) / 2, i, j);
		int s2 = sum(right(p), (L + R) / 2 + 1, R , i, j);
		return s1 + s2;
	}
	void full(int p, int L, int R, int i, int j) {
		if (i > R || j < L) {
			return; // rango actual afuera
		} else if (i <= L && R <= j) { // rango actual adentro
			lazy_val[p] = 1;
			lazy_inv[p] = 0;
		} else {
			full(left(p), L, (L + R) / 2, i, j);
			full(right(p), (L + R) / 2 + 1, R , i, j);
		}
	}
	void empty(int p, int L, int R, int i, int j) {
		if (i > R || j < L) {
			return; // rango actual afuera
		} else if (i <= L && R <= j) { // rango actual adentro
			lazy_val[p] = 0;
			lazy_inv[p] = 0;
		} else {
			empty(left(p), L, (L + R) / 2, i, j);
			empty(right(p), (L + R) / 2 + 1, R , i, j);
		}
	}
	void invert(int p, int L, int R, int i, int j) {
		if (i > R || j < L) {
			return; // rango actual afuera
		} else if (i <= L && R <= j) { // rango actual adentro
			lazy_inv[p] += 1;
		} else {
			invert(left(p), L, (L + R) / 2, i, j);
			invert(right(p), (L + R) / 2 + 1, R , i, j);
		}
	}
public:
	SegmentTree(const vi &A) {
		n = (int)A.size();
		st.assign(4 * n, 0);
		lazy_val.assign(4 * n, -1);
		lazy_inv.assign(4 * n, 0);
		build(A, 1, 0, n - 1);
	}
	void full(int i, int j) {
		full(1, 0, n - 1, i, j);
	}
	void empty(int i, int j) {
		empty(1, 0, n - 1, i, j);
	}
	void invert(int i, int j) {
		invert(1, 0, n - 1, i, j);
	}
	int sum(int i, int j) {
		return sum(1, 0, n - 1, i, j);
	}
};

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		printf("Case %d:\n", tc);
		vi initial; initial.resize(0); initial.reserve(1024000);
		int m; cin >> m;
		while (m--) {
			int t; cin >> t;
			string pirates; cin >> pirates; int l = pirates.length();
			for(int i = 0; i < t; i++)
				for(int j = 0; j < l; j++)
					initial.push_back(pirates[j] - '0');
		}
		SegmentTree st(initial);

		int q; cin >> q; int sc = 0;
		while (q--) {
			char op; int a, b; cin >> op >> a >> b;
			if (op == 'F') {
				st.full(a, b);
			} else if (op == 'E') {
				st.empty(a, b);
			} else if (op == 'I') {
				st.invert(a, b);
			} else if (op == 'S') {
				printf("Q%d: %d\n", ++sc, st.sum(a, b));
			}
		}
	}
	return 0;
}
