#include <iostream>

using namespace std;

bool is_vowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
}

/* 1: vowel
   0: consonant */
bool type(char c) {
	return is_vowel(c) ? 1 : 0;
}

int main() {
	string s, t;
	s.reserve(1010); t.reserve(1010);

	cin >> s >> t;

	if(s.length() != t.length()) {
		cout << "No" << endl;
	} else {
		for(int i = 0; i < s.length(); i++) {
			char sc = s[i];
			char tc = t[i];
			if(type(sc) != type(tc)) {
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	}
	
	return 0;
}
