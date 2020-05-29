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
		int n, m; cin >> n >> m;
		if (n == 1) {
			cout << 0 << endl;
		} else if (n == 2) {
			cout << m << endl;
		} else {
			cout << m * 2 << endl;
		}
	}

	return 0;
}
