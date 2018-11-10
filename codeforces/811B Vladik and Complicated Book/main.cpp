#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

int main() {
	int n, m;
	cin >> n >> m;

	VI P(n);
	for(int i = 0; i < n; ++i) {
		cin >> P[i];
	}

	int l, r, x;
	for(int i = 0; i < m; ++i) {
		cin >> l >> r >> x;
		--l;
		--r;
		--x;
		int nec = x - l;
		int c = 0;
		for(int j = l; j <= r; ++j) {
			if(P[j] < P[x]) {
				++c;
			}
		}
		if(c == nec) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

	return 0;
}
