#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vi v; v.reserve(1000000);
	v.assign(3, 0);
	v.assign(2, 0);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	return 0;
}
