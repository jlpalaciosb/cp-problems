#include <iostream>
#include <vector>
#define INF 2000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int n, a[100000], b[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		cin >> n;
		int fpo = INF, fmo = INF;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == 1 && fpo == INF) fpo = i;
			if (a[i] == -1 && fmo == INF) fmo = i;
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		bool ans = true;
		for (int i = 0; i < n && ans; i++) {
			if (a[i] < b[i]) {
				if (fpo >= i) ans = false;
			} else if (a[i] > b[i]) {
				if (fmo >= i) ans = false;
			}
		}
		cout << (ans ? "YES" : "NO") << endl;
	}

	return 0;
}
