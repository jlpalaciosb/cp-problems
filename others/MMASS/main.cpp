#include <iostream>
#include <stack>
#include <ctype.h>
#include <map>

using namespace std;

int mass_of(char atom) {
	map<char, int> masas;
	masas['H'] = 1;
	masas['C'] = 12;
	masas['O'] = 16;
	return masas[atom];
}

int main() {
	string formula;
	cin >> formula;

	int l = formula.length();

	stack<int> pila;
	pila.push(0);

	for(int i = 0; i < l; i++) {
		char c = formula[i];
		if(c == 'H' || c == 'C' || c == 'O') {
			int t = 1;
			if(i + 1 < l && isdigit(formula[i + 1])) {
				t = formula[i + 1] - '0';
			}
			pila.top() += mass_of(c) * t;
		} else if(c == '(') {
			pila.push(0);
		} else if(c == ')') {
			int t = 1;
			if(i != l - 1 && isdigit(formula[i + 1])) {
				t = formula[i + 1] - '0';
			}
			int mass = pila.top();
			pila.pop();
			pila.top() += mass * t;
		}
	}

	cout << pila.top() << endl;
	
	return 0;
}
