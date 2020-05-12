#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int x, n, m; cin >> x >> n >> m;
		while (x > 20 && n > 0) {
			x = x / 2 + 10;
			n--;
		}
		x = x - 10 * m;
		cout << (x <= 0 ? "YES" : "NO") << endl;
	}

	return 0;
}
