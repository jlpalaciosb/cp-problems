#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vi freq; freq.reserve(200001);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		freq.assign(n + 1, 0);
		int mf = 0, mfa;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			freq[a]++;
			if (freq[a] > mf) {
				mf = freq[a];
				mfa = a;
			}
		}
		int ans = 0;
		for (int a = 1; a <= n; a++) {
			if (freq[a] && a != mfa && ans < mf) {
				ans++;
			}
		}
		if (ans <= mf - 2) {
			ans++;
		}
		cout << ans << endl;
	}

	return 0;
}
