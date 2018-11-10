#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solucionar(int* alturas, int n, int b);
int calcular_alcance(int index, int n, int* alturas);

int alcances[1000];
int sgte[1000];

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
            nro[0] = '\0';
            scanf("%[^\n]", nro); getchar();
            if(strcmp(nro, "") == 0)
                break;
            alturas[n] = atoi(nro);
            n++;
        }
        solucionar(alturas, n, i!=nro_casos-1);
    }
}

void solucionar(int* alturas, int n, int b) {
    int i;
    for(i=0; i<n; i++) {
        alcances[i] = sgte[i] = -1;
    }
    int index_mayor = -1;
    int max_alcance = 0;
    int alcance;
    for(i=0; i<n; i++) {
        alcance = (alcances[i] != -1) ? alcances[i] : calcular_alcance(i, n, alturas);
        if(alcance > max_alcance) {
            max_alcance = alcance;
            index_mayor = i;
        }
    }
    printf("Max hits: %d\n", max_alcance);
    while(index_mayor != -1) {
        printf("%d\n", alturas[index_mayor]);
        index_mayor = sgte[index_mayor];
    }
    if(b)printf("\n");
}

int calcular_alcance(int index, int n, int* alturas) {
    /*if(alcances[index] != -1) {  //no deberia entrar aca
        return alcances[index];
    }*/
    int max_alcance = 0;
    int i;
    int alcance;
    int mayant = -1; /*esto salva*/
    for(i=index+1; i<n; i++) {
        if(alturas[i] > alturas[index] && !(mayant != -1 && alturas[i] > mayant)) {
            mayant = alturas[i];
            alcance = (alcances[i] != -1) ? alcances[i] : calcular_alcance(i, n, alturas);
            if(alcance > max_alcance) {
                max_alcance = alcance;
                sgte[index] = i;
            }
        }
    }
    alcances[i] = max_alcance + 1;
    return alcances[i];
}
