#include <stdio.h>
void CargaMatrizPorFilas(int[][3], int, int);
int IngresaConstante();
void CalcularProducto(int [][3], int, int, int);
void MostrarMatriz(int [][3], int, int);

int main()
{
    int m1[3][3], num;

    CargaMatrizPorFilas(m1, 3, 3);
    MostrarMatriz(m1, 3, 3);
    printf("\nIngrese un numero entero: ");
    num = IngresaConstante();
    CalcularProducto(m1, 3, 3, num);
    MostrarMatriz(m1, 3, 3);

    return 0;
}


void CargaMatrizPorFilas(int m1[][3], int filas, int columnas)
{
    int i, j, aux;
    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
        {
            printf("Ingrese un numero para fila %d columna %d: ", i, j);
            scanf("%d", &m1[i][j]);
        }
    }
}

int IngresaConstante()
{
    int aux;
    scanf("%d", &aux);
    return aux;
}

void CalcularProducto(int m1[][3], int filas, int columnas, int dato)
{
    int i, j;
    for(i=0; i<filas; i++)
        for(j=0; j<columnas; j++)
            m1[i][j] *= dato;
}

void MostrarMatriz(int m1[][3], int filas, int columnas)
{
    int i, j;
    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
            printf("%3d", m1[i][j]);
        printf("\n");
    }
}