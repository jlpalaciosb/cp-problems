#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n, type[200010];

int nb, bf[200010];
void blocks() {
	nb = 1;
	bf[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (type[i] != type[i - 1]) nb++;
		bf[i] = nb;
	}

	if (nb == 1) return;

	if (type[1] == type[n]) {
		nb--;
		for (int i = 1; i <= n; i++) if (bf[i] == n) bf[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		/* code */		
	}
}

int cf[200010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q; cin >> q;
	while (q--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> type[i];

		blocks();

		for (int i = 1; i <= n; i++) {
			if (bf[i] == 1) {
				cf[i] = 1;
			} else if (bf[i] == nb) {
				if (nb == 2) {
					cf[i] = 2;
				} else if (nb % 2 == 0) {
					cf[i] = 2;
				} else if (nb % 2 == 1) {
					cf[i] = 3;
				}
			} else {
				if (bf[i] % 2 == 1) cf[i] = 1;
				else if (bf[i] % 2 == 0) cf[i] = 2;
			}
		}

		int k = 0;
		for (int i = 1; i <= n; i++) k = max(k, cf[i]);
		cout << k << endl;
		for (int i = 1; i <= n; i++) cout << cf[i] << ' ';
		cout << endl;
	}
	return 0;
}
