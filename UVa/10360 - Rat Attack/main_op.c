// igual corrio en el mismo tiemo :c

#include <stdio.h>

int main() {
	int killed[1025][1025], tc, i, j, d, n, max, mx, my, p, x, y, s, pex, pey;
	
	scanf("%d", &tc);
	
	while(tc--) {
		for(i = 0; i < 1025; i++) {
			for(j = 0; j < 1025; j++) {
				killed[i][j] = 0;
			}
		}

		scanf("%d%d", &d, &n);

		max = mx = my = 0;
		
		for(p = 0; p < n; p++) {
			scanf("%d%d%d", &x, &y, &s);
			pex = x + d; pey = y + d;
			for(i = (x - d); i <= pex; i++) {
				for(j = (y - d); j <= pey; j++) {
					if(i > -1 && i < 1025 && j > -1 && j < 1025) {
						killed[i][j] += s;

						if(killed[i][j] > max) {
							max = killed[i][j];
							mx = i; my = j;
						} else if(killed[i][j] == max) {
							if(i < mx || (i == mx && j < my)) {
								mx = i; my = j;
							}
						}
					}
				}
			}
		}

		printf("%d %d %d\n", mx, my, max);
	}

	return 0;
}
