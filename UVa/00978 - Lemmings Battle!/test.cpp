#include <iostream>
#include <set>

using namespace std;

typedef multiset<int> MSI;
typedef MSI::iterator MSIit;

int main() {
	multiset<int> ms;
	ms.insert(3);
	ms.insert(1);
	ms.insert(2);
	ms.insert(1);
	for(MSIit it = ms.begin(); it != ms.end(); ++it) {
		cout << *it << endl;
	}
	cout << "ms.count(1) = " << ms.count(1) << endl;
	cout << "ms.size() = " << ms.size() << endl;
	return 0;
}
