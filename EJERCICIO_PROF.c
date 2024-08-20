#include <stdio.h>
#include <time.h>
#define TAM 10000

void CargaAleatoria(int[], int, int);
void Mostrar (int[], int);
void Ordenar (int[], int);
int BusquedaBinaria (int[], int, int);
int Buscar(int[], int, int);

int main()
{
    int vec[TAM], buscado, pos;
    srand(time(NULL));
    CargaAleatoria(vec,90000, TAM);

    Ordenar(vec, TAM);
    Mostrar(vec, TAM);


    printf("\n\nIngrese el numero a buscar (negativo para terminar):");
    scanf("%d", &buscado);
    while (buscado>=0)
    {
        pos = BusquedaBinaria(vec, buscado, TAM);
        if (pos!=-1)
            printf("Se encontro el numero en el subindice %d", pos);
        else
            printf("El numero no esta en el vector");

        printf("\n\nIngrese el numero a buscar (negativo para terminar):");
        scanf("%d", &buscado);
    }

    return 0;
}


void CargaAleatoria(int v[], int valorMaximo, int ce)
{
    int i, pos;
    for(i=0;i<ce;i++)
    {
        do
        {
            v[i]= rand()%valorMaximo;
            pos = Buscar(v,v[i], i);
        }while (pos !=-1);
    }
}
void Mostrar(int v[], int ce)
{
    int i;

    printf("\n Indice: \n");
    for(i=0;i<ce;i++)
        printf("%8d", i);

    printf("\n\n Valores:  \n");
    for(i=0;i<ce;i++)
       printf("%8d", v[i]);
}

void Ordenar( int v[], int ce)
{
    int i,j, aux;
    for (i=0;i<ce-1;i++)
        for (j=0;j<ce-1-i;j++)
            if (v[j]>v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
}

int BusquedaBinaria (int v[], int buscado, int ce)
{
    int  pos =-1, li=0, ls=ce-1, med;
    int cantIter=0;
    while (pos==-1 && li<=ls)
    {
        cantIter++;
        med=(li+ls)/2;
        if (v[med]==buscado)
            pos =med;
        else
            if (buscado>v[med])
                li = med+1;
            else
                ls = med-1;
    }
    printf("\n\nIteraciones: %d\n\n", cantIter);
    return pos;
}

int Buscar (int v[], int buscado, int ce)
{
    int i=0, pos=-1;
    while(pos==-1 && i<ce)
        if (v[i]==buscado)
            pos =i;
        else
            i++;

    return pos;

}