#include <stdio.h>

void InicializarMatriz(char[][9], char, int, int);
void MostrarMatriz(char[][9], int, int);
void GestionarReserva(char[][9]);
int ContarLetras(char[][9], char, int, int);
void MostrarFilasVacias(char[][9], int, int);
void ContarReservasXFila(char[][9], int [], int, int);
int BuscarValorMaximo(int[], int);
void MostrarValor(int[], int, int);
void ContarReservasXColumnas(char[][9], int[], int, int);
void Ordenar(int[], int[], int);
void MostrarOcupacionButacas(int[], int[], int);

int main()
{
    int vReservasXFila[12]={0}, vReservasXColumna[9]={0}, vButacas[9]={8, 6, 4, 2, 1, 3, 5, 7, 9}, maximo;
    char mCine[12][9];

    InicializarMatriz(mCine, 'D', 12, 9);
    GestionarReserva(mCine);

    printf("Se reservaron: %d", ContarLetras(mCine, 'R', 12, 9));
    printf("Quedaron vacias: %d", ContarLetras(mCine, 'D', 12, 9));
    
    MostrarFilasVacias(mCine, 12, 9);
    
    ContarReservasXFila(mCine, vReservasXFila, 12, 9);
    maximo = BuscarValorMaximo(vReservasXFila, 12);
    MostrarValor(vReservasXFila, maximo, 12);
    
    ContarReservasXColumnas(mCine, vReservasXColumna, 12, 9);
    Ordenar(vReservasXColumna, vButacas, 9);
    MostrarOcupacionButacas(vReservasXColumna, vButacas, 9);
    return 0;
}

void InicializarMatriz(char mCine[][9], char dato, int filas, int columnas)
{
    int f, c;
    for(f=0; f<filas; f++)
        for(c=0; c<columnas; c++)
            mCine[f][c]= dato;
}

void MostrarMatriz(char mCine[][9], int filas, int columnas)
{
    int f, c;
    printf("\n");
    for(f=0; f<filas; f++)
    {
        for(c=0; c<columnas; c++)
            printf("%2c", mCine[f][c]);
        printf("\n");
    }
}

void GestionarReserva(char mCine[][9])
{
    int fila, columna;
    MostrarMatriz(mCine, 12, 9);
    do
    {
        printf("\nIngrese la fila a reservar (finaliza con fila negativa): ");
        scanf("%d", &fila);
    } while (fila>12 || fila==0);

    while (fila>0)  
    {
        do
        {
            printf("Ingrese butaca que desea: ");
            scanf("%d", &columna);
        } while (columna<1 || columna>9);
        // Hay que cambiar su posicion 
        switch (columna)
        {
            case 8: columna=0; 
            break;

            case 6: columna=1; 
            break;

            case 4: columna=2; 
            break;

            case 2: columna=3; 
            break;
            
            case 1: columna=4; 
            break;

            case 3: columna=5; 
            break;

            case 5: columna=6; 
            break;

            // case 7: columna=7;
            // break;

            case 9: columna=8;
            break;
            
            default:
                break;
        }

        fila = fila-1;
        if(mCine[fila][columna]=='R')
        {
            printf("******EL LUGAR ESTA OCUPADO - SELECCIONE OTRO******");
        }
        else   
        {
            mCine[fila][columna]='R';
        }

        MostrarMatriz(mCine, 12, 9);
        do
        {
            printf("\nIngrese la fila a reservar (finaliza con fila negativa): ");
            scanf("%d", &fila);
        } while (fila>12 || fila==0);
    }
}

int ContarLetras(char mCine[][9], char letra, int filas, int columnas)
{
    int f, c, contador=0;
    for(f=0; f<filas; f++)
        for(c=0; c<columnas; c++)
            if(mCine[f][c]==letra)
                contador++;
    return contador;
}

void MostrarFilasVacias(char mCine[][9], int filas, int columnas)
{
    int f, c, contador;
    for(f=0; f<filas; f++)
    {
        contador=0;
        for(c=0; c<columnas; c++)
            if(mCine[f][c]=='D')
                contador++;
        if(contador==0)
            printf("\nLa Fila %d esta vacia", f+1);
    }
}

void ContarReservasXFila(char mCine[][9], int vReservasXFila[], int filas, int columnas)
{
    int f, c, contador;
    for(f=0; f<filas; f++)
    {
        vReservasXFila[f]=0;
        for(c=0; c<columnas; c++)
            if(mCine[f][c]=='R')
                vReservasXFila[f]++;
    }    
}

int BuscarValorMaximo(int vReservasXFila[], int filas)
{
    int f, max;

    max = vReservasXFila[0];
    for(f=1; f<filas; f++)
        if(vReservasXFila[f]>max)
            max = vReservasXFila[f];
    return max;
}

void MostrarValor(int vReservasXFila[], int maximo, int filas)
{
    int f;
    printf("El valor maximo es: %d y se encuentra en la/las filas:", maximo);
    for(f=0; f<filas; f++)
        if(vReservasXFila[f]==maximo)
            printf("\n%d", f+1);
}

void ContarReservasXColumnas(char mCine[][9], int vReservasXColumna[], int filas, int columnas)
{
    int f, c, contador;
    for(c=0; c<columnas; c++)
    {
        vReservasXColumna[c]=0;
        for(f=0; f<filas; f++)
            if(mCine[f][c]=='R')
                vReservasXColumna[c]++;
    }   
}

void Ordenar(int v0[], int v1[], int columnas)
{
    int i, j, aux;
    for (i=0; i<columnas-1; i++)
        for (j=0; j<columnas-1-i; j++) // VECTOR A ORDENAR EN IF
            if(v0[j] < v0[j+1])
            {
                aux = v0[j];
                v0[j] = v0[j+1];
                v0[j+1] = aux;

                aux = v1[j];
                v1[j] = v1[j+1];
                v1[j+1] = aux;
            }
}

void MostrarOcupacionButacas(int vReservasXColumna[], int vButacas[], int N)
{
    int i;
    printf("\n\nButaca Cantidad");
    for(i=0; i<N; i++)
        printf("\n%6d %8d", vButacas[i], vReservasXColumna[i]);
}