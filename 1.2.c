#include <stdio.h>

int  Buscar(int[], int, int);
int  leeYvalida(int, int);
void IngresaCodigos(int[], int);
int  IngresaProducto();
void MostrarListado(int[], int[], int);
int  Maximo(int[], int);
int  Minimo(int[], int);
void MostrarValor(int[], int[], int, int);

int main()
{
    int vCodigoProductos[10], vPedidos[10]={0};
    int codigo, posicion, cantidad, max, min;

    IngresaCodigos(vCodigoProductos, 10);
    codigo = IngresarProducto();
    while(codigo!=0)
    {
        posicion = Buscar(vCodigoProductos, codigo, 10);
        if(posicion != -1)
        {
            cantidad = IngresarPositivo();
            vPedidos[posicion]+=cantidad;
        }
        else
            Printf("CODIGO NO EXISTE(COMO RACING)\n");
        codigo = IngresarProducto();
    }
    ListaDeProductos(vCodigoProductos, vPedidos, 10);
    max = ValorMaximo(vPedidos, 10);
    printf("VALOR MAXIMO: %d\n", max);
    MostrarValor(vCodigoProductos, vPedidos, max, 10);
    min = ValorMinimo(vPedidos, 10);
    printf("VALOR MINIMO: %d\n", min);
    MostrarValor(vCodigoProductos, vPedidos, min, 10);
    return 0;
}

int Buscar(int vCodigoProductos[], int datoABuscar, int N)  // N = Cantidad de Elementos
{
    int i=0, posicion=-1;
    while (posicion==-1 && i<N)
    {
        if (vCodigoProductos[i]==datoABuscar)
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

void IngresaCodigos(int vCodigoProductos[], int N)
{
    int i, posicion, codigo;

    for (i=0; i<N; i++)
    {
        do
        {
            printf("CODIGO (DE 4 CIFRAS Y SIN DUPLICAR):\n");
            codigo = leeYvalida(1000, 9999);
            posicion = Buscar(vCodigoProductos, codigo, i);
            if (posicion!=-1)
                printf("Dato Duplicado. Ingrese otro.\n");
        }while (posicion!=-1);
        vCodigoProductos[i] = codigo;
    }
}
int IngresarProducto()
{
    int codigo;
    printf("\nINGRESAR CODIGO DE PRODUCTO: ");
    scanf("%d", &codigo);
    return codigo;
}

int IngresarPositivo()
{
    int cantidad;
    do
    {
        printf("\nCANTIDAD DE UNIDADES SOLICITADAS: ");
        scanf("%d", &cantidad);
        if(cantidad <= 0)
            printf("VALOR ERRONEO\n");
    }while(cantidad<=0);
    return cantidad;
}

void MostrarListado(int vCodigoProductos[], int vPedidos[], int N)
{
    int i;
    printf("\nCODIGO  UNIDADES");
    for(i=0; i<N; i++)
    {
        printf("\n%6d  %8d", vCodigoProductos[i], vPedidos[i]);
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

void MostrarValor(int vCodigoProductos[], int vPedidos[], int valor, int N)
{
    int i;
    printf("EL/LOS PRODUCTOS: \n");
    for ( i = 0; i < N; i++)
    {
        if(vPedidos[i] == valor)
            printf("%d\n", vCodigoProductos[i]);
    }
}