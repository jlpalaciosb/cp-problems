#include <bits/stdc++.h>

using namespace std;

struct row { int p, w; };
bool cmp(const row & r1, const row & r2) {
   return r1.w < r2.w;
}

int main() {
	int n; scanf("%d\n", &n);

	vector<row> rows(n);

	for(int i = 0; i < n; i++) {
		int w; scanf("%d%*c", &w);
		rows[i] = (row){i + 1, w};
	}
	
	sort(rows.begin(), rows.end(), cmp);

	stack<int> fe; // for extroverts =)
	int fi = 0; // for introverts =)

	for(int i = 0; i < 2 * n; i++) {
		char p = getchar();
		if(p == '0') {
			printf("%d ", rows[fi].p);
			fe.push(rows[fi].p);
			fi++;
		} else {
			printf("%d ", fe.top());
			fe.pop();
		}
	}

	return 0;
}
