#include <stdio.h>
#include <stdlib.h>
void Carga(int[], int);
void Mostrar(int[], int);

int main()
{
    int vec[10];
    Carga(vec, 10);
    Mostrar(vec, 10);
    return 0;
}

void Carga(int vec[], int N)
{
    int i;
    printf("Ingrese 10 VALORES ENTEROS:\n");
    for(i=0; i<N; i++)
        scanf("%d", vec+i);
}

void Mostrar(int vec[], int N)
{
    int i;
    printf("Los VALORES ENTEROS ingresados son: \n");
    for(i=0; i<N; i++)
        printf("%d\n", *(vec+i));
}
/*
#include <stdio.h>
void Carga(int[], int);
void Mostrar(int[], int);

int main()
{
    int vec[5];
    Carga(vec, 5);
    Mostrar(vec, 5);
    return 0;
}

void Carga(int vec[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("ingrese un numero: ");
        scanf("%d", vec+i);
    }
}

void Mostrar(int vec[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
        printf("%d\n", *(vec+i));
}
*/