#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

bool is_correct(int a, int b, int c) {
	return (a + b) > c && (a + c) > b && (b + c) > a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		int x[2]; x[0] = a; x[1] = b;
		int y[2]; y[0] = b; y[1] = c;
		int z[2]; z[0] = c; z[1] = d;
		bool ans = false;
		for (int i = 0; i < 2 && !ans; i++) {
			for (int j = 0; j < 2 && !ans; j++) {
				for (int k = 0; k < 2 && !ans; k++) {
					if (is_correct(x[i], y[j], z[k])) {
						cout << x[i] << ' ' << y[j] << ' ' << z[k] << endl;
						ans = true;
					}
				}
			}
		}
	}

	return 0;
}
