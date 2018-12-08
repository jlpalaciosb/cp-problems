#include <iostream>
#include <bitset>

using namespace std;

int main() {
	int n;
	cin >> n;

	for(int i = 1; i <= n; i++) {
		string edge, vertices;
		bitset<26> bs;
		int ne, nv, nconn, ntrees, nacorns;

		bs.reset();
		ne = 0;
		while(cin >> edge, edge[0] != '*') {
			char u = edge[1];
			char v = edge[3];
			bs.set(u - 'A');
			bs.set(v - 'A');
			ne += 1;
		}

		cin >> vertices;

		nv = (vertices.length() + 1) / 2;
		nconn = nv - ne; /* número de componentes conexas */
		nacorns = nv - bs.count();
		ntrees = nconn - nacorns;

		cout << "There are " << ntrees << " tree(s) and " << nacorns << " acorn(s)." << endl;
	}

	return 0;
}
