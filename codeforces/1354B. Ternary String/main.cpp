#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int a = -1, b = -1, c = -1, ans = INF;
		for (int i = 0; i < s.length(); i++) {
			int v = s[i] - '0';
			if (v == 1) {
				a = i;
			} else if (v == 2) {
				b = i;
			} else {
				c = i;
			}
			if (a != -1 && b != -1 && c != -1) {
				ans = min(ans, max(a, max(b, c)) - min(a, min(b, c)) + 1);
			}
		}
		if (ans == INF) {
			ans = 0;
		}
		cout << ans << endl;
	}

	return 0;
}
