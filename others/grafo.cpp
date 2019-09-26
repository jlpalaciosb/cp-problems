#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int nro_vertices = 10;
	vector<vector<int> > gd(nro_vertices); //grafo dirigido

	gd[0].push_back(9);
	gd[3].push_back(3);
	gd[3].push_back(4);

	return 0;
}
