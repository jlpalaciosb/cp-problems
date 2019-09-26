// resuelto con la ayuda del tutorial c:

#include <iostream>
#define debug(x) cerr << #x << " = " << x << endl
#define MAXN 300010
#define MAXA (1 << 20) + 10
using namespace std;
typedef long long ll;

int n, pref[MAXN];
int count[MAXA][2];

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int a; cin >> a;
		pref[i] = pref[i - 1] ^ a;
	}

	ll res = 0;
	count[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		res += count[pref[i]][i % 2];
		count[pref[i]][i % 2] += 1;
	}

	cout << res << endl;

	return 0;
}
