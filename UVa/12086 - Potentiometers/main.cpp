#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int A[200000], len;

class SegmentTree {
public:
	vi st;
	int n;
	int left (int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }
	void build(int p, int L, int R) {
		if (L == R) st[p] = A[L];
		else {
			build(left(p) , L , (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R );
			st[p] = st[left(p)] + st[right(p)];
		}
	}
	int rsq(int p, int L, int R, int i, int j) {
		if (i > R || j < L) return 0;
		if (i <= L && R <= j) return st[p];
		int mid = (L + R) >> 1;
		int s1 = rsq(left(p) , L , mid, i, j);
		int s2 = rsq(right(p), mid + 1, R , i, j);
		return s1 + s2;
	}
	SegmentTree() {
		n = len;
		st.assign(4 * n, 0);
		build(1, 0, n - 1);
	}
	int rsq(int i, int j) { return rsq(1, 0, len - 1, i, j); }
	void update(int i, int v) { update(1, 0, len - 1, i, v); }
	void update(int p, int L, int R, int i, int v) {
		if (L == R && L == i) { st[p] = v; return; }
		int mid = (L + R) >> 1;
		if (i <= mid) update(left(p) , L , mid, i, v);
		else update(right(p), mid + 1, R , i, v);
		st[p] = st[left(p)] + st[right(p)];
	}
};

int main() {
	int cn = 0;
	while (cin >> len, len != 0) {
		cn++; if (cn > 1) cout << endl;
		printf("Case %d:\n", cn);

		for(int i = 0; i < len; i++) scanf("%d", A + i);
		SegmentTree *st = new SegmentTree();

		while (true) {
			getchar(); char op = getchar();
			if (op == 'E') {
				getchar(); getchar();
				break;
			}
			if (op == 'S') {
				int x, r; cin >> x >> r;
				st->update(x - 1, r);
			}
			if (op == 'M') {
				int x, y; cin >> x >> y;
				printf("%d\n", st->rsq(x - 1, y - 1));
			}
		}
	}
	return 0;
}
