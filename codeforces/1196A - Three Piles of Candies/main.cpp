#include <iostream>
using namespace std;

int main() {
	int q;
	long long a, b, c;

	cin >> q;
	while (q--) {
		cin >> a >> b >> c;
		cout << (a + b + c) / 2 << endl;
	}
	
	return 0;
}
