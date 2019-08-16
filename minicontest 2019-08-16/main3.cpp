// Codeforces 550A - Two Substrings
#include <iostream>
using namespace std;

int main() {
	string str; cin >> str;
	int n = str.length();

	int ab1, ab2, ab = false, ba1, ba2, ba = false;
	for (int i = 0; i + 1 < n; i++) {
		if (str[i] == 'A' && str[i + 1] == 'B') {
			if (!ab) ab1 = i;
			ab2 = i;
			ab = true;
		}
		if (str[i] == 'B' && str[i + 1] == 'A') {
			if (!ba) ba1 = i;
			ba2 = i;
			ba = true;
		}
	}

	if (ab && ba && (abs(ab1 - ba2) >= 2 || abs(ab2 - ba1) >= 2))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
