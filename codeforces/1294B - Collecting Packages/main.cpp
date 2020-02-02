#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int mi[1001], ma[1001], fl1[1001], mx = 0;
		memset(fl1, false, sizeof fl1);
		char s[2010]; int sl = 0;

		int n; scanf("%d", &n);
		while (n--) {
			int x, y; scanf("%d%d", &x, &y);
			if (!fl1[x]) {
				fl1[x] = true;
				mi[x] = ma[x] = y;
			}
			mi[x] = min(mi[x], y);
			ma[x] = max(ma[x], y);
			mx = max(mx, x);
		}

		int cy = 0, fl2 = true;
		for (int x = 0; x <= mx; x++) {
			if (fl1[x]) {
				if (mi[x] < cy) {
					fl2 = false;
					break;
				}
				int c = ma[x] - cy;
				while (c--) s[sl++] = 'U';
				cy = ma[x];
			}
			if (x < mx) s[sl++] = 'R';
		}

		if (fl2) {
			printf("YES\n");
			s[sl] = '\0';
			printf("%s\n", s);
		} else printf("NO\n");
	}

	return 0;
}
