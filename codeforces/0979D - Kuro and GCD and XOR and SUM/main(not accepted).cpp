#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b);

int main() {
	int q;
	cin >> q;

	vector<int> array; array.reserve(q);

	for(int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if(t == 1) {
			int u;
			cin >> u;
			array.push_back(u);
		} else {
			int x, k, s;
			cin >> x >> k >> s;
			int v = -1;
			for(int j = 0; j < array.size(); ++j) {
				int e = array[j];
				if(gcd(x, e) % k != 0)
					continue;
				if(x + e > s)
					continue;
				if(v == -1 || (x ^ e > x ^ v))
					v = e;
			}
			cout << v << endl;
		}
	}

	return 0;
}

int gcd(int a, int b) {
    while ( b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
