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
			for(int i = (x - d); i <= (x + d); i++) {
				for(int j = (y - d); j <= (y + d); j++) {
					if(i > -1 && i < 1025 && j > -1 && j < 1025) {
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
		}

		cout << mx << " " << my << " " << max << endl;
	}
	return 0;
}
