#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k; cin >> n >> k;
	string t; cin >> t;

	string a = "", b = t;
	for (int i = 0; i < n - 1; i++) {
		bool eq = true;
		int k = 0;
		for (int j = n - i - 1; j < n; j++) {
			if (t[k++] != t[j]) {
				eq = false;
				break;
			}
		}
		if (eq) {
			a = t.substr(0, i + 1);
			b = t.substr(i + 1);
		}
	}

	cout << a;
	for (int i = 0; i < k; i++) {
		cout << b;
	}
	cout << endl;

	return 0;
}
