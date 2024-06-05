#include <stdio.h>

int  Buscar(int[], int, int);
int  leeYvalida(int, int);
void IngresaCodigos(int[], int);
void CargaPedidos(int[], int[]);
void MostrarListado(int[], int[], int);
int  Maximo(int[], int);
void MostrarMaxUnidades(int[], int[], int);
void MostrarMinUnidades(int[], int[], int);

int main()
{
    int vProductos[10], vUnidades[10]={0};
    IngresaCodigos(vProductos, 10);
    CargaPedidos(vProductos, vUnidades);
    MostrarListado(vProductos, vUnidades, 10);
    MostrarMaxUnidades(vProductos, vUnidades, 10);
    MostrarMinUnidades(vProductos, vUnidades, 10);
    return 0;
}

int Buscar(int vProductos[], int datoABuscar, int N)  // N = Cantidad de Elementos
{
    int i=0, posicion=-1;
    while (posicion==-1 && i<N)
    {
        if (vProductos[i]==datoABuscar)
            posicion = i;
        else
            i++;
    }
    return posicion;
}

int leeYvalida(int limiteInf, int limiteSup)
{
    int aux;
    do
    { 
        scanf("%d", &aux);
    } while (aux<limiteInf || aux>limiteSup);

    return aux;
}

void IngresaCodigos(int vProductos[], int N)
{
    int i, posicion, aux;

    for (i=0; i<N; i++)
    {
        do
        {
            printf("Ingrese un Codigo(de 4 cifras y sin repetir): \n");
            aux = leeYvalida(1000, 9999);
            posicion = Buscar(vProductos, aux, i);
            if (posicion!=-1)
                printf("Dato Duplicado. Ingrese otro.\n");
        } while (posicion!=-1);
        vProductos[i] = aux;
    }
}

void CargaPedidos(int vProductos[], int vUnidades[])
{
    int i, codigo, unidades, posicion;
    do
    {       
        printf("\nIngrese el codigo de un producto: ");
        scanf("%d", &codigo);
        posicion = Buscar(vProductos, codigo, 10);
        if(posicion == -1 && codigo!=0)
            printf("\nCODIGO NO VALIDO, INGRESE OTRO.");
    }while(posicion == -1 && codigo!=0);

    while(codigo!=0)
    {
        printf("Ingrese cantidad de unidades: ");
        scanf("%d", &unidades);
        vUnidades[posicion] += unidades;
        do
        {       
            printf("\nIngrese el codigo de un producto: ");
            scanf("%d", &codigo);
            posicion = Buscar(vProductos, codigo, 10);
            if(posicion == -1 && codigo!=0)
                printf("\nCodigo no valido. Ingrese otro.");
        } while (posicion == -1 && codigo!=0);
    }  
}

void MostrarListado(int vProductos[], int vUnidades[], int N)
{
    int i;
    printf("\nCODIGO  UNIDADES");
    for(i=0; i<N; i++)
    {
        printf("\n%6d  %8d", vProductos[i], vUnidades[i]);
    }
}

int Maximo(int v[], int N)
{
    int max=v[0], i;
    for(i=1; i<N; i++)
    {
        if(v[i]>max)
            max=v[i];
    }
    return max;
}

void MostrarMaxUnidades(int vProductos[], int vUnidades[], int N)
{
    int i, max;
    max=Maximo(vUnidades, 10);
    printf("\nPRODUCTO/S  MAYOR CANTIDAD DE UNIDADES");
    for ( i = 0; i < N; i++)
    {
        if(vUnidades[i]==max)
            printf("\n%10d  %26d", vProductos[i], max);
    }
}

int Minimo(int v[], int N)
{
    int min=v[0], i;
    for(i=1; i<N; i++)
    {
        if(v[i]<min)
            min=v[i];
    }
    return min;
}

void MostrarMinUnidades(int vProductos[], int vUnidades[], int N)
{
    int i, min;
    min=Minimo(vUnidades, 10);
    printf("\nPRODUCTO/S  MENOR CANTIDAD DE UNIDADES");
    for ( i = 0; i < N; i++)
    {
        if(vUnidades[i]==min)
            printf("\n%10d  %26d", vProductos[i], min);
    }
}