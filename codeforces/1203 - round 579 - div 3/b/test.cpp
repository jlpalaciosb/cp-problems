#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef unordered_multiset<int> conjunto;
typedef conjunto::iterator conj_it;


int main() {
	conjunto lados;
	lados.insert(1);
	lados.insert(1);
	lados.insert(2);
	lados.erase(lados.find(1));
	cout << 'b' << (lados.find(33) == lados.end()) << endl;
	for (conj_it it = lados.begin(); it != lados.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
