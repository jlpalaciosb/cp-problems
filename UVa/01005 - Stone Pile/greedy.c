#include <stdio.h>
#include <stdlib.h>

int compare_int( const void* a, const void* b )
{
    if( *(int*)a == *(int*)b ) return 0;
    return *(int*)a < *(int*)b ? -1 : 1;
}


int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int vector[n];
	int suma1 = 0;
	int suma2 = 0;
	int i;
	for ( i = 0; i < n; ++i)
	{
		scanf("%d", vector+i);
	}
	qsort( vector, n, sizeof(int), compare_int );
	for ( i = n-1; i >= 0; --i)
	{
		if (suma1>suma2)
		{
			suma2 += vector[i];
		}else{
			suma1 += vector[i];
		}
	}

	printf("%d\n", abs(suma1 - suma2));

	return 0;
}

