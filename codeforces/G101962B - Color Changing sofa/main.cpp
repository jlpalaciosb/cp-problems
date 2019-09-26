#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool fits(const string &sofa, const string &room, int i);

int main() {
	string room, sofa1, sofa2;
	cin >> room >> sofa1;
	sofa2 = sofa1;
	reverse(sofa2.begin(), sofa2.end());

	int n = room.length();
	int m = sofa1.length();
	int c = 0;

	for(int i = 0; i <= n - m; i++) {
		if(fits(sofa1, room, i) || fits(sofa2, room, i)) {
			c++;
		}
	}

	cout << c << endl;
	return 0;
}

bool fits(const string &sofa, const string &room, int i) {
	vector<char> colors = {'_', '_'};
	int j = 0;
	for(int k = 0; k < sofa.length(); k++) {
		if(colors[sofa[j] - '0'] == '_') {
			colors[sofa[j] - '0'] = room[i];
		} else if(room[i] != colors[sofa[j] - '0']) {
			return false;
		}
		j++;
		i++;
	}
	return true;
}
