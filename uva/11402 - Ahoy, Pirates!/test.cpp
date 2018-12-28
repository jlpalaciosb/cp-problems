#include <iostream>

using namespace std;

int main() {
	/*int i = 0;
	cout << (i >> 1) << endl;
	cout << sizeof(short) << endl;*/
	string str;
	cout << str.capacity() << endl;

	str.reserve(1000);
	str = "hola";
	cout << str.capacity() << endl;
	cout << str.length() << endl;

	str = "";
	cout << str.capacity() << endl;
	cout << str.length() << endl;

	int a = 1;
	a = !a;
	cout << "neg = " << a << endl;
	a = !a;
	cout << "neg = " << a << endl;
	
	return 0;
}
