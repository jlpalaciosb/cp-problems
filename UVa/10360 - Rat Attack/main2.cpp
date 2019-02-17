// Este es el que corre en el menor tiempo

#include <iostream>

using namespace std;

int main() {
	int killed[1025][1025];
	
	int tc; cin >> tc;
	while(tc--) {
		for(int i = 0; i < 1025; i++) {
			for(int j = 0; j < 1025; j++) {
				killed[i][j] = 0;
			}
		}

		int d, n;
		cin >> d >> n;

		int max = 0, mx = 0, my = 0;
		
		for(int p = 0; p < n; p++) {
			int x, y, s;
			cin >> x >> y >> s;

			int psx = x - d; if(psx < 0) psx = 0;
			int psy = y - d; if(psy < 0) psy = 0;

			int pex = x + d; if(pex > 1024) pex = 1024;
			int pey = y + d; if(pey > 1024) pey = 1024;

			for(int i = psx; i <= pex; i++) {
				for(int j = psy; j <= pey; j++) {
					killed[i][j] += s;

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

		cout << mx << " " << my << " " << max << endl;
	}
	return 0;
}
