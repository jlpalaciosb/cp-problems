#include <iostream>

using namespace std;

int main() {
	char c;
	string str;
	cin >> c;
	getchar();
	getline(cin, str);
	int co = 0;

	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == c)
		{
			co++;

		}
	}

	cout << co << endl;
	
	return 0;
}