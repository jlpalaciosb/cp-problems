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
		int n, x, a[100]; cin >> n >> x;
		vi b; b.assign(200, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[a[i] - 1] = 1;
		}

		for (int i = 0; i < 200; i++) {
			if (b[i] == 0 && x > 0) {
				b[i] = 1;
				x--;
			}
		}

		int v = 0, i = 0;
		while (b[i] != 0 && i < 200) {
			v++;
			i++;
		}

		cout << v << endl;

	}

	return 0;
}
