// WA

#include <iostream>
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

string s;
int len;

bool all_equal(int lim) {
	for(int i = 1; i < lim; i++) {
		if(s[i] != s[0]) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> s;
	len = s.length();

	if(all_equal(len)) {
		cout << "Impossible" << endl;
	} else {
		if(len % 2 == 0) {
			cout << 1 << endl;
		} else {
			if(all_equal(len / 2)) {
				cout << "Impossible" << endl;
			} else {
				cout << 2 << endl;
			}
		}
	} 

	return 0;
}
