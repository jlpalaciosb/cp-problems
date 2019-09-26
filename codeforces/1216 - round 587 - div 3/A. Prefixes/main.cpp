#include <iostream>
using namespace std;

int main() {
	int n; char s[200001];
	cin >> n >> s;
	int c = 0;
	for (int i = 0; i < n; i += 2) {
		if (s[i] == s[i + 1]) {
			c++;
			s[i] = s[i] == 'a' ? 'b' : 'a';
		}
	}
	cout << c << endl << s << endl;
	return 0;
}
