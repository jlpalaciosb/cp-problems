#include <iostream>
#include <list>

using namespace std;

typedef list<string>::iterator LSit;

int main() {
	list<string> l;

	l.push_back("hola");
	l.push_back("chau");

	LSit it = l.begin();
	it = ++it;

	cout << *it;

	return 0;
}
