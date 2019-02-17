/* El ejercicio consiste en encontrar en Longest Increasing Sebsequence de la lista */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct elemento {
    int valor;
    int alcance; /* Cuántos elementos mayores que él hay después de él (inclusivo) */
    int index_sgte; /* Para reconstruir la subsecuencia */
};
typedef struct elemento Elemento;

void solucionar(Elemento lista[], int longitud, int ultimo_Problema);
int calcular_alcance(Elemento lista[], int longitud, int index);

int main() {
    int nro_casos;
    scanf("%d", &nro_casos); getchar();

    Elemento lista[1000];
    int longitud;

    char nro[20];

    getchar();

    for(int i = 0; i < nro_casos; i++) {
        longitud = 0;
        while (1) {
            nro[0] = '\0';
            scanf("%[^\n]", nro); getchar();
            if(strcmp(nro, "") == 0)
                break;
            lista[longitud].valor = atoi(nro);
            lista[longitud].alcance = lista[longitud].index_sgte = -1;
            longitud++;
        }
        solucionar(lista, longitud, i != nro_casos - 1);
    }

    return 0;
}

void solucionar(Elemento lista[], int longitud, int ultimo_Problema) {
    int init_longest = -1; /* Índice del 1er elemento del LIS */ 
    int max_alcance = 0;
    int alcance;
    for(int i = 0; i < longitud; i++) {
        alcance = calcular_alcance(lista, longitud, i);
        if(alcance > max_alcance) {
            max_alcance = alcance;
            init_longest = i;
        }
    }
    printf("Max hits: %d\n", max_alcance);
    while(init_longest != -1) {
        printf("%d\n", lista[init_longest].valor);
        init_longest = lista[init_longest].index_sgte;
    }
    if(ultimo_Problema)
        printf("\n");
}

int calcular_alcance(Elemento lista[], int longitud, int index) {
    if(lista[index].alcance != -1) {  //no deberia entrar aca
        return lista[index].alcance;
    }
    int max_alcance = 0;
    int alcance;
    int may_ant = -1; /*esto salva: ultimo elemento procesado (mayor anterior) */
    for(int i = index + 1; i < longitud; i++) {
        if(lista[i].valor > lista[index].valor) {
            if (lista[i].valor > may_ant && may_ant != -1) //sí o sí alcance va a ser menor que max_alcance, entonce podemos saltar
                continue;
            may_ant = lista[i].valor;
            alcance = calcular_alcance(lista, longitud, i);
            if(alcance > max_alcance) {
                max_alcance = alcance;
                lista[index].index_sgte = i;
            }
        }
    }
    lista[index].alcance = max_alcance + 1;
    return lista[index].alcance;
}
