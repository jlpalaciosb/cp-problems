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
		string s; cin >> s; int n = s.length();
		int ans = (int)1e9;

		for (int i = 0; i <= n; i++) {
			int c = 0;
			for (int j = 0; j < i; j++) {
				if (s[j] != '0') {
					c++;
				}
			}
			for (int j = i; j < n; j++) {
				if (s[j] != '1') {
					c++;
				}
			}
			ans = min(ans, c);
		}

		for (int i = 0; i <= n; i++) {
			int c = 0;
			for (int j = 0; j < i; j++) {
				if (s[j] != '1') {
					c++;
				}
			}
			for (int j = i; j < n; j++) {
				if (s[j] != '0') {
					c++;
				}
			}
			ans = min(ans, c);
		}

		cout << ans << endl;
	}

	return 0;
}
