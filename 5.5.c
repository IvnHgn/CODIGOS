#include <stdio.h>
#include <stdlib.h>

void Carga(int[], int);
void Mostrar(int[], int);
int* Buscar(int[], int);

int main()
{
    int num, vec[10], *puntero, i;
    Carga(vec, 10);
    do
    {
        printf("\nINGRESE UN NUMERO(FIN CON '0' o NUMERO NEGATIVO): ");
        scanf("%d", &num);
        puntero = Buscar(vec, num);
        if(puntero != NULL)
        {
            for(i=0; i<10; i++)
            {
                if(puntero==vec+i)
                    printf("EL NUMERO %d ESTA EN LA POSICION %d DEL VECTOR.\n", num, i+1);
            }
        }
    }while(num!=0 && num>0);
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

int *Buscar(int vec[], int num)
{
    int *puntero, i;

    puntero = NULL;
    for(i=0; i<10; i++)
        if(num == *(vec+i))
            puntero = vec+i;
    return puntero;
}

void Mostrar(int vec[], int N)
{
    int i;
    printf("\nLos VALORES ENTEROS ingresados son: \n");
    for(i=0; i<N; i++)
        printf("%d\n", *(vec+i));
}