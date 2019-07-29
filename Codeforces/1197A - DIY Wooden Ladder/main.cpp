#include <iostream>
using namespace std;

int main() {
	int t, n, a, m1, m2, m;

	cin >> t;
	while (t--) {
		cin >> n;

		cin >> m1;
		cin >> m2;
		if (m1 < m2) {
			int aux = m1;
			m1 = m2;
			m2 = aux;
		}

		for (int i = 0; i < n - 2; i++) {
			cin >> a;
			if (a > m1) {
				m2 = m1;
				m1 = a;
			} else if (a > m2) {
				m2 = a;
			}
		}

		m = min(m1, m2) - 1;
		cout << min(m, n - 2) << endl;
	}

	return 0;
}
