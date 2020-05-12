#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string t, s; s.reserve(200);

	int T; cin >> T;
	while (T--) {
		cin >> t;

		bool ae = true;
		for (int i = 1; i < t.length(); i++) {
			if (t[i] != t[i - 1]) {
				ae = false;
				break;
			}
		}
		if (ae) {
			cout << t << endl;
			continue;
		}

		if (t[0] == '0') s = "0";
		else s = "1";
		for (int i = 1; i < 2 * t.length(); i++) {
			s.push_back(s[i - 1] == '0' ? '1' : '0');
		}
		cout << s << endl;
	}

	return 0;
}
