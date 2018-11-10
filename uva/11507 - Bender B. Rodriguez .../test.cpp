#include <iostream>
#include <vector>
#include <map>

using namespace std;

void print_vector(const vector<int> &v) {
	int n = v.size();
	cout << "{";
	for(int i = 0; i < n; ++i) {
		cout << v[i] << (i != n - 1 ? ", " : "");
	}
	cout << "}" << endl;
}

int main() {
	/*for(int i = 0; i < 5; ++i) {
		vector<int> v = {1, 2, 3};
		cout << v[1];
		v[1] = 1000;
	}
	string inst;
	cin >> inst;
	cout << (inst[0] == 'a') << endl;
	vector<int> v = {1, 2, 3};
	print_vector(v);
	map<vector<int>, string> m;
	m[{0, 1}] = "uno";
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	cout << m[v];
	string s = "ab";
	cout << (s == "ab") << endl;*/
	cout << abs(-1) << endl;
	return 0;
}
