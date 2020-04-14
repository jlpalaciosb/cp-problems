#include <iostream>
#include <vector>
#include <cmath>
#define INF 2000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a; cin >> a;
		int m = a;
		int md = 0;
		for (int i = 1; i < n; i++) {
			cin >> a;
			m = max(m, a);
			md = max(md, m - a);
		}
		if (md > 0) cout << (int)(floor(log((double)md) / log((double)2)) + 1) << endl;
		else cout << 0 << endl;
	}

	return 0;
}
