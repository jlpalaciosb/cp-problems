#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	for(int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		int mayor;
		cin >> mayor;
		for(int j = 1; j < n; ++j) {
			int a;
			cin >> a;
			if(a > mayor) {
				mayor = a;
			}
		}
		cout << "Case " << i + 1 << ": " << mayor << endl;
	}

	return 0;
}
