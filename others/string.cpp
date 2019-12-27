#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	string a;
	string b;

	cin >> a;
	cin >> b;

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	string otro = "hola";
	string copy = otro;
	otro[2] = 'j';

	cout << "otro=" << otro << endl;
	cout << "copy=" << copy << endl;

	return 0;
}
