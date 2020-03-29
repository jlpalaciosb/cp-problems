#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		ll c = 0;
		int b1, b2;
		for (int i = 1; i <= n - 1; i++) {
			if (c + i >= k) {
				b1 = i + 1;
				b2 = k - c;
				break;
			} else c += i;
		}
		string s(n, 'a');
		s[n - b1] = s[n - b2] = 'b';
		cout << s << endl;
	}
	return 0;
}
