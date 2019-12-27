#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int nro_casos;
    scanf("%d", &nro_casos); getchar();
    int alturas[1000], n;
    char nro[20];

    getchar();

    int i;
    for(i=0; i<nro_casos; i++) {
        n = 0;
        while (1) {
            gets(nro);
            if(strcmp(nro, "") == 0)
                break;
            alturas[n] = atoi(nro);
            n++;
        }

        int j;
        for(j=0; j<n; j++)
            printf("%d ", alturas[j]);
    }
}
