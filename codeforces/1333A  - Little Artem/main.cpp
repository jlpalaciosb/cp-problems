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
		cout << 'W';
		for (int i = 0; i < m - 1; i++) cout << 'B';
		cout << endl;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				cout << 'B';
			}
			cout << endl;
		}
	}

	return 0;
}
