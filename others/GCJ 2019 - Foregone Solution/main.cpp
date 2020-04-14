#include <iostream>
using namespace std;
int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		string n; cin >> n; int len = n.length();
		string a(len, '0'), b(len, '0');
		for (int i = 0; i < len; i++)
			if (n[i] == '4') a[i] = b[i] = '2';
			else a[i] = n[i];
		int i = 0; while (b[i++] == '0'); b = b.substr(i - 1);
		printf("Case #%d: %s %s\n", t, a.c_str(), b.c_str()); }
	return 0; }