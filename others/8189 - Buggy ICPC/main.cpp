#include <iostream>

using namespace std;

bool is_vowel(char c);
int number_of_vowels(const string &str);

int main() {
	string str;
	str.reserve(100001);
	while(getline(cin, str)) {
		int l = str.size();
		int nv = number_of_vowels(str);
		int nw;
		if(nv == 0) {
			nw = 1;
		} else {
			if(!is_vowel(str[0])) {
				nw = 0;
			} else if(nv == 1) {
				nw = l;
			} else {
				int c = 0, c1, c2;
				for(int i = 0; i < l; ++i) {
					if(is_vowel(str[i])) {
						c += 1;
						if(nv % 2 == 0) {
							if(c == nv / 2) {
								c1 = i;
							} else if(c == nv / 2 + 1) {
								c2 = i;
								break;
							}
						} else {
							if(c == nv / 2 + 1) {
								c1 = i;
							} else if(c == nv / 2 + 2) {
								c2 = i;
								break;
							}
						}
					}
				}
				nw = c2 - c1;
			}
		}
		cout << nw << endl;
	}
	return 0;
}

bool is_vowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int number_of_vowels(const string &str) {
	int c = 0, l = str.size();
	for(int i = 0; i < l; ++i) {
		if(is_vowel(str[i])) c += 1;
	}
	return c;
}
