#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

double pi = 3.14159265358979323846;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(9);

	int t; cin >> t;
	while (t--) {
		double n; cin >> n;
		cout << fixed << (1.0 / tan(pi / (2.0 * n))) << endl;
	}

	return 0;
}
