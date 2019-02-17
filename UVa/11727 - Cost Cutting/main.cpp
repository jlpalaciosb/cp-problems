#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;

	for(int i = 1; i <= t; ++i) {
		vector<int> salaries(3);
		cin >> salaries[0] >> salaries[1] >> salaries[2];
		sort(salaries.begin(), salaries.end());
		cout << "Case " << i << ": " << salaries[1] << endl;
	}

	return 0;
}
