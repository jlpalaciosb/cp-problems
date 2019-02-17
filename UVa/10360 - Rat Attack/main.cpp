#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int x, y;
} cell;

int main() {
	queue<cell> affected;
	int killed[1025][1025] = {0};
	
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		while(!affected.empty()) { // Hacemos cero las celdas que no son cero
			cell af = affected.front();
			killed[af.x][af.y] = 0;
			affected.pop();
		}

		int d, n;
		scanf("%d%d", &d, &n);

		int max = 0, mx = 0, my = 0;
		
		for(int p = 0; p < n; p++) {
			int x, y, q;
			scanf("%d%d%d", &x, &y, &q);

			int psx = x - d; if(psx < 0) psx = 0;
			int psy = y - d; if(psy < 0) psy = 0;

			int pex = x + d; if(pex > 1024) pex = 1024;
			int pey = y + d; if(pey > 1024) pey = 1024;

			for(int i = psx; i <= pex; i++) {
				for(int j = psy; j <= pey; j++) {
					if(killed[i][j] == 0) {
						cell af = {i, j};
						affected.push(af);
					}

					killed[i][j] += q;

					if(killed[i][j] > max) {
						max = killed[i][j];
						mx = i;
						my = j;
					} else if(killed[i][j] == max) {
						if(i < mx) {
							mx = i;
							my = j;
						} else if(i == mx && j < my) {
							mx = i;
							my = j;
						}
					}
				}
			}
		}

		printf("%d %d %d\n", mx, my, max);
	}
	return 0;
}
