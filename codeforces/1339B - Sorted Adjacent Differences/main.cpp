#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vi a(300000);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.begin() + n);
		if (n % 2 == 0) {
			int i = n / 2 - 1;
			int j = 1;
			while (i >= 0) {
				cout << a[i] << ' ';
				i = i + j;
				if (j < 0) j = -(j - 1);
				else j = -(j + 1);
			}
		} else {
			int i = n / 2;
			int j = 1;
			while (i < n) {
				cout << a[i] << ' ';
				i = i + j;
				if (j < 0) j = -(j - 1);
				else j = -(j + 1);
			}
		}
		cout << endl;
	}

	return 0;
}
