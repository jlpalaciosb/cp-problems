#include <iostream>
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

int main() {
	int n, v;
	cin >> n >> v;

	int p = 1;
	int t = 0;
	int d = 0;

	while(p < n) {
		if(t < n - p) {
			int charge = min(v - t, n - p);
			t += charge;
			d += charge * p;
		}
		t--;
		p++;
	}

	cout << d << endl;

	return 0;
}
