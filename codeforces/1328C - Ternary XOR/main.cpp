#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

char a[50010], b[50010];

int main() {
    ios::sync_with_stdio(false);
  	cin.tie(0);

  	int t; cin >> t;
  	while (t--) {
  		int n; cin >> n;
  		string x; cin >> x;

  		bool f = false;
  		for (int i = 0; i < n; i++) {
  			if (x[i] == '2') {
  				if (f) {
  					a[i] = x[i];
  					b[i] = '0';
  				} else a[i] = b[i] = '1';
  			} else if (x[i] == '1') {
  				if (f) {
  					a[i] = x[i];
  					b[i] = '0';
  				} else {
  					f = true;
					a[i] = '0';
					b[i] = '1';
  				}
  			} else {
  				a[i] = b[i] = '0';
  			}
  		}

  		a[n] = b[n] = '\0';
  		printf("%s\n%s\n", a, b);
  	}

	return 0;
}
