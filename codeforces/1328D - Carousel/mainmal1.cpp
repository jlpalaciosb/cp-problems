#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n;
int t[200010], c[200010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q; cin >> q;
	while (q--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> t[i];
		nb = nblocks();
		if (nb == 1) {
			for (int i = 0; i < n; i++) cout << "1 ";
		} else {
			int i = 1;
			for (int b = 1; b <= nb - 1; b++) {
				int cb = b % 2;
				int t1 = t[i];
				while (t[i++] == t1) {
					c[i] = cb;
				}
			}
			if (t[n] != t[1]) {
				int cb;
				if (nb % 2 == 1) cb = 2;
				else cb = 0;
				while (i++ <= n) {
					c[i] = cb;
				}
			} else {
				int cb = c[1];
				
				while ()
			}
		}

		for (int i = 1; i <= n; i++) {
			printf("%d ", c[i]);
		}
		cout << endl;
	}

	return 0;
}
