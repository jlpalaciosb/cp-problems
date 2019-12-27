#include <iostream>
#include <algorithm>
#define debug(x) cerr << #x << " = " << x << endl
using namespace std;

int n, d, r, morning[100], evening[100];

int main() {
	while(cin >> n >> d >> r, n > 0) {
		for(int i = 0; i < n; i++) {
			cin >> morning[i];
		}
		for(int i = 0; i < n; i++) {
			cin >> evening[i];
		}
		sort(morning, morning + n);
		sort(evening, evening + n, greater<int>());
		int s, e = 0;
		for(int i = 0; i < n; i++) {
			s = morning[i] + evening[i];
			if(s > d) {
				e += s - d;
			}
		}
		cout << (e * r) << endl;
	}
	return 0;
}
