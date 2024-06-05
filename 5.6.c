#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5

void Mostrar(int[], int);
int *BuscarMax(int[], int);
void CargaAleatoria(int[], int, int);

int main()
{
    int i, vec[5], *puntero;

    srand(time(NULL));              
    CargaAleatoria(vec, TAM, 1000);
    Mostrar(vec, TAM);
    puntero = BuscarMax(vec, TAM);
    printf("EL VALOR MAXIMO ES %d", *puntero);
    for(i=0; i<5; i++)
    {
        if(vec+i==puntero)
            printf(" Y SE ENCUENTRA EN LA POSICION %d", i+1);
    }
    return 0;
}

void CargaAleatoria(int vec[], int N, int max)
{
    int i;
    for(i=0; i<N; i++)
        *(vec+i) = rand() % max;
}

int *BuscarMax(int vec[], int N)
{
    int *puntero, max, i;

    max = vec[0];
    puntero = vec;
    for(i=1; i<N; i++)
        if(vec[i] > max)
        {
            max = vec[i];
            puntero = vec+i;
        }
    return puntero; 
}

void Mostrar(int vec[], int N)
{
    int i;
    printf("\nLos VALORES ENTEROS ingresados son: \n");
    for(i=0; i<N; i++)
        printf("%d\n", *(vec+i));
}