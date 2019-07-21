#include <iostream>
#include <set>
using namespace std;
typedef set<string>::iterator ssit;

int main() {
	string s1 = "jose";
	string s2 = "luis";

	set<string> the_set;
	//the_set.insert(s1);
	//the_set.insert(s2);
	the_set = {"asldkf", "alsdkfkf"};

	// for (ssit it = the_set.begin(); it != the_set.end(); it++) {
	// 	((string)(*it)).push_back('j');
	// }
	// no no

	for (ssit it = the_set.begin(); it != the_set.end(); it++) {
		cout << *it << endl;
	}

	return 0;
}
