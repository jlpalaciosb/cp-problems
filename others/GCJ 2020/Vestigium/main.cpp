#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int mat[100][100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, k = 0, r = 0, c = 0; cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
				if (i == j) k += mat[i][j];
			}
		}

		vi flag1, flag2;
		for (int i = 0; i < n; i++) {
			flag1.assign(n + 1, 0);
			flag2.assign(n + 1, 0);
			int cnt1 = 0;
			int cnt2 = 0;
			for (int j = 0; j < n; j++) {
				if (!flag1[mat[i][j]]) {
					flag1[mat[i][j]] = 1;
					cnt1++;
				}
				if (!flag2[mat[j][i]]) {
					flag2[mat[j][i]] = 1;
					cnt2++;
				}
			}
			if (cnt1 < n) r++;
			if (cnt2 < n) c++;
		}
		
		printf("Case #%d: %d %d %d\n", t, k, r, c);
	}

	return 0;
}
