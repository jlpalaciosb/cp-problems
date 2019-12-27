#include <algorithm>
#include <iostream>
#define x first
#define y second.first
#define z second.second
using namespace std;
typedef pair<int, pair<int, int>> iii;

class node {
public:
	int L, R, m;
	node *left, *right;
	node(int L_, int R_) {
		L = L_; R = R_;
		m = -1;
		left = right = NULL;
	}
	int rmq(int i, int j) {
		if (m == -1 || R < i || j < L) return -1;
		if (i <= L && R <= j) {
			return m;
		}
		return max(left->rmq(i, j), right->rmq(i, j));
	}
	void set(int i, int v) {
		if (i < L || i > R) return;

		if (L == R && L == i) {
			m = max(m, v);
		} else {
			if (m == -1) {
				left = new node(L, (L + R) / 2);
				right = new node((L + R) / 2 + 1, R);
			}
			left->set(i, v);
			right->set(i, v);
			m = max(left->m, right->m);
		}
	}
};

int main() {
	int n; cin >> n;
	iii vec[n];
	for (int i = 0; i < n; ++i) cin >> vec[i].x;
	for (int i = 0; i < n; ++i) cin >> vec[i].y;
	for (int i = 0; i < n; ++i) cin >> vec[i].z;
	sort(vec, vec + n);

	int m = 1000000000;
	node root(0, m);
	int f = -1, l = -1, c = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (l == -1) l = i;
		if (i == 0 || vec[i - 1].x < vec[i].x) f = i;
		if (root.rmq(vec[i].y + 1, m) > vec[i].z) c++;
		if (f != -1) {
			for (int j = f; j <= l; ++j) {
				root.set(vec[j].y, vec[j].z);
			}
			f = l = -1;
		}
	}
	cout << c << endl;
	return 0;
}
