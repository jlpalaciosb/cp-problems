#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b, c, n;
		scanf("%d%d%d%d", &a, &b, &c, &n);
		int m = max(a, max(b, c));
		n -= (m - a) + (m - b) + (m - c);
		if (n < 0 || n % 3 != 0) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
