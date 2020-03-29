#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s; cin >> s;
	cout << s << endl;
	reverse(s.begin(), s.end());
	cout << s << endl;
	cout << s.substr(s.length() - 1) << endl;
	cout << s.substr(s.length()) << endl;

	return 0;
}
