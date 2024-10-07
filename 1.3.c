#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Buscar(int[], int, int);
void CargaAleatoria(int[], int, int);

int main()
{
    int i, vGrupos[5];
    srand(time(NULL));
    CargaAleatoria(vGrupos, 5, 5);
    printf("ORDEN DE EXPOSICION DE LOS 5 GRUPOS:");
    for(i=0; i<5; i++)
        printf("\n%d", vGrupos[i]);
    return 0;
}

void CargaAleatoria(int v[], int valorMaximo, int N)
{
    int i, posicion;
    for(i=0; i<N; i++) 
    {
        do  
        {
            v[i] = rand()%valorMaximo+1;
            posicion = Buscar(v, v[i], i);
        }while(posicion!=-1);
    } 
}

int Buscar(int v[], int datoABuscar, int N)
{
    int i=0, posicion=-1;
    while(posicion==-1 && i<N)
    {
        if(v[i]==datoABuscar)
            posicion = i;
        else
            i++;
    }
    return posicion;
}