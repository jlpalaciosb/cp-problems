#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(3);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
	 	cout << "Case " << t << ": ";
	 	double d, v, u; cin >> d >> v >> u;
	 	if (u > v) {
	 		double t1 = d / u;
	 		double t2 = d / (u * cos(asin(v / u)));
	 		double ans = abs(t1 - t2);
	 		if (ans < 0.00001) cout << "can't determine" << endl;
	 		else cout << fixed << abs(t1 - t2) << endl;
	 	} else {
	 		cout << "can't determine" << endl;
	 	}
	}

	return 0;
}
