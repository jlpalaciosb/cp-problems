#include <iostream>
#include <vector>
#define UNDEF -1

using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> ve(100, UNDEF);
	ve[0] = 1;
	cout << ve[10] << endl;
	
	ve.push_back(449);
	cout << ve[100] << endl;

	return 0;
}
