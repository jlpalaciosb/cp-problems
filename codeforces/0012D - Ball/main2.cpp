#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <map>
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
		if (i <= L && R <= j) return m;
		int tmp1 = -1, tmp2 = -1;
		if (left != NULL) tmp1 = left->rmq(i, j);
		if (right != NULL) tmp2 = right->rmq(i, j);
		return max(tmp1, tmp2);
	}
	void set(int i, int v) { // se asume que L <= i <= R
		if (L == R) {
			m = v;
		} else {
			int mid = (L + R) >> 1;

			if (i <= mid) {
				if (left == NULL) left = new node(L, mid);
				left->set(i, v);
				m = max(m, left->m);
			} else {
				if (right == NULL) right = new node(mid + 1, R);
				right->set(i, v);
				m = max(m, right->m);
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	iii vec[n];
	for (int i = 0; i < n; ++i) cin >> vec[i].x;
	for (int i = 0; i < n; ++i) cin >> vec[i].y;
	for (int i = 0; i < n; ++i) cin >> vec[i].z;
	sort(vec, vec + n);

	int m = 1000000000;
	node root(0, m);
	int f = -1, l = -1, c = 0;
	unordered_map<int, int> mp; mp.reserve(600000);
	for (int i = n - 1; i >= 0; --i) {
		if (l == -1) l = i;
		if (i == 0 || vec[i - 1].x < vec[i].x) f = i;
		if (root.rmq(vec[i].y + 1, m) > vec[i].z) c++;
		
		if (f > 0) {
			for (int j = f; j <= l; ++j) {
				int y_ = vec[j].y, z_ = vec[j].z;
				if (mp.count(y_) == 0 || z_ > mp[y_]) {
					root.set(y_, z_);
					mp[y_] = z_;
				}
			}
			f = l = -1;
		}
	}
	cout << c << endl;
	return 0;
}
