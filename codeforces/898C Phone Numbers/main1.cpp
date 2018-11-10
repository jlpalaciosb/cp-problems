#include <iostream>
#include <map>
#include <vector>
#include <list>

using namespace std;

bool esSufijo(const string &s1, const string &s2);

int main() {
	map<string, list<string>> records;
	
	int n; cin >> n; getchar();

	for(int i = 0; i < n; ++i) {
		string name;
		cin >> name; getchar();

		int m;
		cin >> m; getchar();

		for(int j = 0; j < m; ++j) {
			string phone;
			cin >> phone; getchar();
			records[name].push_back(phone);
		}
	}

	for(map<string, list<string>>::iterator it = records.begin(); it != records.end(); ++it) {
		for(list<string>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
			for(list<string>::iterator it3 = it->second.begin(); it3 != it->second.end();) {
				if(esSufijo(*it3, *it2) || (it3 != it2 && *it3 == *it2)) {
					++it3;
					list<string>::iterator aux = it3;
					--it3;
					it->second.erase(it3);
					it3 = it2;
				} else {
					++it3;
				}
			}
		}
	}

	cout << records.size() << endl;
	for(map<string, list<string>>::iterator it = records.begin(); it != records.end(); ++it) {
		string name = it->first;
		cout << name << " " << it->second.size();
		for(list<string>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
			cout << " " << *it2;
		}
		cout << endl;
	}

	
	return 0;
}

/* Retorna true si s1 es sufijo de s2 */
bool esSufijo(const string &s1, const string &s2) {
	int n1 = s1.length();
	int n2 = s2.length();
	if(n1 >= n2) {
		return false;
	}
	int in2 = n2 - n1;
	for(int i = 0; i < n1; ++i) {
		if(s1[i] != s2[in2 + i]) {
			return false;
		}
	}
	return true;
}
