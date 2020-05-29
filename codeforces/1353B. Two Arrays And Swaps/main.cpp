#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vi a, b; a.resize(n); b.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end(), greater<int>());
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
		}
		for (int i = 0; i < k; i++) {
			if (a[i] < b[i]) {
				sum = sum - a[i] + b[i];
			} else {
				break;
			}
		}
		cout << sum << endl;
	}

	return 0;
}
