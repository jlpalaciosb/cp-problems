#include <stdio.h>

int main() {
	int m, n, t, ti, spent[10000], burger[10000];
	while (scanf("%d%d%d", &m, &n, &t) != EOF) {
		for (ti = 0; ti <= t; ti++) {
			char better; /* m or c */
			if (ti < m && ti < n) better = '-';
			else if (ti < m) better = 'n';
			else if (ti < n) better = 'm';
			else if (m + spent[ti - m] > n + spent[ti - n]) better = 'm';
			else if (m + spent[ti - m] < n + spent[ti - n]) better = 'n';
			else if (burger[ti - m] > burger[ti - n]) better = 'm';
			else better = 'n';
			if (better == '-') {
				spent[ti] = 0;
				burger[ti] = 0;
			} else if (better == 'm') {
				spent[ti] = m + spent[ti - m];
				burger[ti] = 1 + burger[ti - m];
			} else { /* better == 'n' */
				spent[ti] = n + spent[ti - n];
				burger[ti] = 1 + burger[ti - n];
			}
		}
		if (spent[t] == t) printf("%d\n", burger[t]);
		else printf("%d %d\n", burger[t], t - spent[t]);
	}
	return 0;
}
