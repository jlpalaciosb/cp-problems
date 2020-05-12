#include <cmath>
#include <iostream>
#include <vector>
#define PI 3.14159265359
#define ZERO 0.00001
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	double a, b, v, A, s;
	while (cin >> a >> b >> v >> A >> s, a > 0) {
		A *= PI / 180;
		double dx = v / 2 * s * cos(A);
		double dy = v / 2 * s * sin(A);
		int H = 0;
		if (dx >= a / 2) {
			H = 1;
			dx -= a / 2;
		}
		H += (int)(dx / a);
		cout << H << ' ';
		int V = 0;
		if (dy >= b / 2) {
			V = 1;
			dy -= b / 2;
		}
		V += (int)(dy / b);
		cout << V << endl;
	}

	return 0;
}
