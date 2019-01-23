#include <iostream>
#include <algorithm>

using namespace std;

int served[30]; // served[i] = number of customers served with the tower i (1 <= i <= n)

int selected[30]; // store the r selected towers, from selected[i] = 1 if the i (1 <= i <= n) tower is selected
int selArray[30]; // selection array for compute all combinations (or subsets of size r)

/* common[i][0] = number of towers that serve the common area i (1 <= i <= m)
   then come the towers number, common[i][25] = number of customers in the common area i */
int common[15][30];

void equalize(int a1[], int a2[], int a, int b) {
	for(int i = a; i <= b; i++) a1[i] = a2[i];
}

int main() {
	int cn = 1;
	while(true) {
		int n, r;
		cin >> n >> r;
		if(n == 0  && r == 0) break;

		for(int i = 1; i <= n; i++)
			cin >> served[i];

		int m; cin >> m;
		for(int i = 1; i <= m; i++) {
			int t; cin >> t; common[i][0] = t;
			for(int j = 1; j <= t; j++) cin >> common[i][j];
			cin >> common[i][25];
		}

		int max = 0;

		for(int i = 1; i <= n; i++)
			selArray[i] = (i <= n - r) ? 0 : 1;

		do {
			int sum = 0;
			for(int i = 1; i <= n; i++)
				if(selArray[i]) sum += served[i];

			for(int i = 1; i <= m; i++) {
				int t = common[i][0];
				int q = 0;
				for(int j = 1; j <= t; j++)
					if(selArray[common[i][j]]) q++;
				if(q > 1) sum -= (q - 1) * common[i][25];
			}

			if(sum >= max) {
				max = sum;
				equalize(selected, selArray, 1, n);
			}
		} while(next_permutation(selArray + 1, selArray + n + 1));

		cout << "Case Number  " << cn++ << endl;
		cout << "Number of Customers: " << max << endl;
		cout << "Locations recommended: ";
		int tmp = 1;
		for(int i = 1; i <= n; i++)
			if(selected[i]) cout << i << (++tmp <= r ? " " : "");
		cout << endl << endl;
	}
	return 0;
}
