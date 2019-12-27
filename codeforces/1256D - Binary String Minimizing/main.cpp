#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int q; cin >> q;
	char s[1000010];

	while (q--) {
		int n; ll k; cin >> n >> k;
		scanf("%s", s);

		int c = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				c++;
			} else {
				if (k >= c) {
					printf("0");
					k -= c;
				} else {
					for (int j = 1; j <= c - k; j++) printf("1");
					printf("0");
					for (int j = 1; j <= k; j++) printf("1");
					for (int j = i + 1; j < n; j++) printf("%c", s[j]);
					c = 0;
					break;
				}
			}
		}
		for (int i = 1; i <= c; i++) printf("1");
		cout << endl;
	}
	return 0;
}
