#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 20

void CargaAleatoria(int[], int, int);
int Minimo(int[], int);
int Maximo(int[], int);
void MostrarMinimo(int[], int, int);
void MostrarMaximo(int[], int, int);
/*
a. Mostrar el menor valor e indicar cuantas veces se repite
b. Mostrar el mayor valor e indicar en que posición/posiciones se encuentra
*/

int main()
{
    int vec[20], min, max;

    srand(time(NULL));              
    CargaAleatoria(vec, TAM, 1000);
    min= Minimo(vec, TAM);
    max= Maximo(vec, TAM);
    MostrarMinimo(vec, min, TAM);
    MostrarMaximo(vec, max, TAM);   
    return 0;
}

// N= Cantidad de Elementos
void CargaAleatoria(int vec[], int N, int max)
{
    int i;
    for(i=0; i<N; i++)
    {
        vec[i]=rand()%max;
    }

}

int Minimo(int vec[], int N)
{
    int min=vec[0], i;
    for(i=1; i<N; i++)
    {
        if(vec[i]<min)
            min=vec[i];
    }
    return min;
}

int Maximo(int vec[], int N)
{
    int max=vec[0], i;
    for(i=1; i<N; i++)
    {
        if(vec[i]>max)
            max=vec[i];
    }
    return max;
}

void MostrarMinimo(int vec[], int min, int N)
{
    int contador=0, i;
    
    for(i=0; i<N; i++)
    {
        if(vec[i]==min)
            contador++;
    }
    printf("\nEl valor minimo es: %d y se repite %d veces.", min, contador);
    
}

void MostrarMaximo(int vec[], int max, int N)
{
    int i;
    printf("El valor maximo es: %d y se encuentra en las siguientes posiciones del vector:\n", max);
    for(i=0; i<N; i++)
    {
        if(vec[i]==max)
            printf("%d\n", i+1);
    }
}