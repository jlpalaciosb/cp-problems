#include <iostream>
#include <vector>
#include <list>
#define UNDEF 0

using namespace std;

vector<int> v;
int n;

bool sePuede(int i12) {
	int i11 = 1;
	int c1 = 2;
	int r1 = v[i12] - v[1];

	int i21, i22;
	int c2 = i12 - 1 - 1;
	int r2 = UNDEF;

	if(c2 >= 1) {
		i21 = 2;
	}
	if(c2 >= 2) {
		i22 = 3;
		r2 = v[i22] - v[i21];
	}

	bool posible = true;
	for(int i = i12 + 1; i <= n; ++i) {
		int e = v[i];
		if(e == v[i11] + r1 * c1) { //el elemento puede ir en la progresion 1
			if(c2 == 0) { //la progresion 2 está vacia, entonces ponemos en la progresion 1
				c1 += 1;
				continue;
			} else if(c2 == 1) { //tambien puede ir en la progresion 2
				// si ponemos en 2, 1 ya no crece, entonces miramos si se forma la progresion en 2
				int temp_r2 = v[i] - v[i21];
				int temp_c2 = 2;
				int temp_posible = true;
				for(int j = i + 1; j <= n; ++j) {
					if(v[j] == v[i21] + temp_r2 * temp_c2) {
						temp_c2 += 1;
					} else {
						temp_posible = false;
						break;
					}
				}
				if(temp_posible) {
					posible = true;
					break;
				}
			} else if(c2 >= 2 && e == v[i21] + r2 * c2) { //tambien puede ir en la progresion 2
				// si ponemos en 2, 1 ya no crece, entonces miramos si se forma la progresion en 2
				int temp_c2 = c2 + 1;
				int temp_posible = true;
				for(int j = i + 1; j <= n; ++j) {
					if(v[j] == v[i21] + r2 * temp_c2) {
						temp_c2 += 1;
					} else {
						temp_posible = false;
						break;
					}
				}
				if(temp_posible) {
					posible = true;
					break;
				}
			}
			// Si llegamos hasta aca es xq:
			// - El elemento no pudo ir en la progresion 2
			// - Si pudo ir, no se completa la progresion en 2
			c1 += 1; // entonces agregamos el elemento a la primera progresion
		} else {
			if(c2 == 0) {
				i21 = i;
				c2 += 1;
			} else if(c2 == 1) {
				i22 = i;
				r2 = v[i22] - v[i21];
				c2 += 1;
			} else if(e != v[i21] + r2 * c2) { //tampoco puede ir en la progresion 2
				posible = false;
				break;
			} else {
				c2 += 1; //se ingresa en la progresion 2
			}
		}
	}

	return posible;
}

void construir(int i12) {
	list<int> l1, l2;

	int i11 = 1;
	int c1 = 2;
	int r1 = v[i12] - v[1];

	int i21, i22;
	int c2 = i12 - 1 - 1;
	int r2 = UNDEF;

	if(c2 >= 1) {
		i21 = 2;
	}
	if(c2 >= 2) {
		i22 = 3;
		r2 = v[i22] - v[i21];
	}

	l1.push_back(v[i11]);
	l1.push_back(v[i12]);

	for(int i = i11 + 1; i < i12; ++i) {
		l2.push_back(v[i]);
	}


	bool posible = true;
	for(int i = i12 + 1; i <= n; ++i) {
		int e = v[i];
		if(e == v[i11] + r1 * c1) { //el elemento puede ir en la progresion 1
			if(c2 == 0) { //la progresion 2 está vacia, entonces ponemos en la progresion 1
				l1.push_back(e);
				c1 += 1;
				continue;
			} else if(c2 == 1) { //tambien puede ir en la progresion 2
				// si ponemos en 2, 1 ya no crece, entonces miramos si se forma la progresion en 2
				int temp_r2 = v[i] - v[i21];
				int temp_c2 = 2;
				int temp_posible = true;
				for(int j = i + 1; j <= n; ++j) {
					if(v[j] == v[i21] + temp_r2 * temp_c2) {
						temp_c2 += 1;
					} else {
						temp_posible = false;
						break;
					}
				}
				if(temp_posible) {
					//agregamos todo a la progresion 2
					l2.push_back(e);
					for(int j = i + 1; j <= n; ++j) {
						l2.push_back(v[j]);
					}
					posible = true;
					break;
				}
			} else if(c2 >= 2 && e == v[i21] + r2 * c2) { //tambien puede ir en la progresion 2
				// si ponemos en 2, 1 ya no crece, entonces miramos si se forma la progresion en 2
				int temp_c2 = c2 + 1;
				int temp_posible = true;
				for(int j = i + 1; j <= n; ++j) {
					if(v[j] == v[i21] + r2 * temp_c2) {
						temp_c2 += 1;
					} else {
						temp_posible = false;
						break;
					}
				}
				if(temp_posible) {
					//agregamos todo a la progresion 2
					l2.push_back(e);
					for(int j = i + 1; j <= n; ++j) {
						l2.push_back(v[j]);
					}
					posible = true;
					break;
				}
			}
			// Si llegamos hasta aca es xq:
			// - La segunda progresion no esta vacia, o
			// - El elemento no pudo ir en la progresion 2, o
			// - Si pudo ir, no se completa la progresion en 2
			c1 += 1; // entonces agregamos el elemento a la primera progresion
			l1.push_back(e);
		} else {
			if(c2 == 0) {
				l2.push_back(e);
				i21 = i;
				c2 += 1;
			} else if(c2 == 1) {
				l2.push_back(e);
				i22 = i;
				r2 = v[i22] - v[i21];
				c2 += 1;
			} else if(e != v[i21] + r2 * c2) { //tampoco puede ir en la progresion 2, esto no puede pasar aca
				posible = false;
				break;
			} else {
				l2.push_back(e);
				c2 += 1; //se ingresa en la progresion 2
			}
		}
	}

	if(l2.size() == 0) {
		list<int>::iterator it = l1.end();
		--it;
		l2.push_back(*it);
		l1.erase(it);
	}

	for(list<int>::iterator it = l1.begin(); it != l1.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	for(list<int>::iterator it = l2.begin(); it != l2.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	cin >> n;
	v.resize(n+1);
	for(int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	int i21, i22, r2, c2 = 0;
	bool solved = false;
	int i;
	for(i = 2; i <= n; ++i) {
		if(sePuede(i)) {
			construir(i);
			solved = true;
			break;
		} else {
			if(c2 == 0) {
				i21 = i;
				c2 += 1;
			} else if(c2 == 1) {
				i22 = i;
				r2 = v[i22] - v[i21];
				c2 += 1;
			} else {
				if(v[i] == v[i21] + r2 * c2) {
					c2 += 1;
				} else {
					solved = false;
					break;
				}
			}
		}
	}

	if(!solved) {
		cout << "No solution" << endl;
	}
	
	return 0;
}
