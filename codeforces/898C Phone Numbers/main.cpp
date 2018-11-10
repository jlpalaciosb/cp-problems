#include <iostream>
#include <map>
#include <vector>
#include <list>

using namespace std;

typedef map<string, list<string>>::iterator MSLSit;
typedef list<string>::iterator LSit;

#define name first
#define phones second

/* Retorna true si s1 es sufijo de s2 */
bool isSufix(const string &s1, const string &s2);

int main() {
	map<string, list<string>> records;
	
	int n;
	cin >> n; getchar();

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

	for(MSLSit it = records.begin(); it != records.end(); ++it) {
		for(LSit it2 = it->phones.begin(); it2 != it->phones.end(); ++it2) {
			for(LSit it3 = it->phones.begin(); it3 != it->phones.end(); ) {
				if(it3 != it2 && isSufix(*it3, *it2)) {
					LSit aux = it3;
					++it3;
					it->phones.erase(aux);
				} else {
					++it3;
				}
			}
		}
	}

	cout << records.size() << endl;
	for(MSLSit it = records.begin(); it != records.end(); ++it) {
		cout << it->name << " " << it->phones.size();
		for(LSit it2 = it->phones.begin(); it2 != it->phones.end(); ++it2) {
			cout << " " << *it2;
		}
		cout << endl;
	}
	
	return 0;
}

bool isSufix(const string &s1, const string &s2) {
	int n1 = s1.length();
	int n2 = s2.length();
	if(n1 > n2) {
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
