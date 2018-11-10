#include <iostream>
#include <stack>
#include <ctype.h>

using namespace std;

int main() {
	stack<int> pila;

	pila.push(3);
	pila.top() += 3;

	cout << pila.top() << endl;

	return 0;
}
