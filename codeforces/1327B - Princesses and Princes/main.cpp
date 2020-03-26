#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<set<int>> vsi;
typedef vector<bool> vb;
typedef vi::iterator vi_it;

int n;
vsi ds;
vvi pl;
vb df, pf;

void process() {
	for (int i = 1; i <= n; i++) {
		if (!ds[i].empty()) {
			int p = *(ds[i].begin());
			df[i] = pf[p] = true;
			for (vi_it it = pl[p].begin(); it != pl[p].end(); it++) {
				ds[*it].erase(p);
			}
		}
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		scanf("%d", &n);
		ds = vsi(n + 1);
		pl = vvi(n + 1);
		for (int i = 1; i <= n; i++) {
			int k; scanf("%d", &k);
			for (int j = 1; j <= k; j++) {
				int p; scanf("%d", &p);
				ds[i].insert(p);
				pl[p].push_back(i);
			}
		}
		df.assign(n + 1, false); pf.assign(n + 1, false);
		process();
		int di = -1, pi = -1;
		for (int i = 1; i <= n; i++) if (!df[i]) { di = i; break; }
		for (int i = 1; i <= n; i++) if (!pf[i]) { pi = i; break; }
		if (di != -1 && pi != -1) {
			printf("IMPROVE\n%d %d\n", di, pi);
		} else printf("OPTIMAL\n");
	}
	return 0;
}
