#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);
		string s; cin >> s;
		int c = 0;
		for (int i = 0; i < s.length(); i++) {
			int v = s[i] - '0';
			if (c < v) {
				for (int j = 0; j < v - c; j++) printf("(");
			} else if (c > v) {
				for (int j = 0; j < c - v; j++) printf(")");
			}
			c = v;
			printf("%d", v);
		}
		while (c--) printf(")");
		printf("\n");
	}

	return 0;
}
