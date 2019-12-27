#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int q; cin >> q;
	while (q--) {
		int a, b, n, s; scanf("%d%d%d%d", &a, &b, &n, &s);
		if ((ll)a * n < s) {
			if (b >= s - (ll)a * n) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		} else {
			if (b >= s % n) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
	return 0;
}
