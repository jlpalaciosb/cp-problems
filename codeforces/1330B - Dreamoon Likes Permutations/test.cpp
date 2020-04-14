#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vi v(3);
	v[0] = 1; v[1] = 2; v[2] = 3;
	reverse(v.begin(), v.end());

	for (int i = 0; i < 3; i++)
	cout << v[i] << ' ';

	return 0;
}
