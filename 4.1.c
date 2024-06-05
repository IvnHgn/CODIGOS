#include <stdio.h>
#include <string.h>

typedef struct
{
    char codigo[6];
    float precio;
    char descripcion[31];
    int cantidadDeUnidadesVendidas;
    float importeTotalVendido;
}PRODUCTO;

void LeerTexto(char[], int);
int Buscar(PRODUCTO[], char[], int);
int  CargaDeProductos(PRODUCTO[], int);
void CargaDeVentas(PRODUCTO[], int);
void Listar(PRODUCTO[], int);

int main()
{
    PRODUCTO vProducto[50];
    int cantidadDeProductos;

    cantidadDeProductos= CargaDeProductos(vProducto, 50);
    CargaDeVentas(vProducto, cantidadDeProductos);
    Listar(vProducto, cantidadDeProductos);
    return 0;
}
void LeerTexto(char texto[], int largo)
{
    int i;
    fgets(texto, largo, stdin);
    i=0;
    while (texto[i]!='\0')
    {
        if (texto[i]=='\n')
            texto[i]='\0';
        else
            i++;
    }
}

int BuscarDescripcion(PRODUCTO vProducto[], char descripcion[], int N)
{
    int i=0, posicion=-1;

    while(i<N && posicion == -1)
    {
        if(!(strcmpi(vProducto[i].descripcion, descripcion)))   // Si devuelve 0 --> falso || Si devuelve != 0 --> verdadero
            posicion = i;
        else
            i++;
    }
    return posicion;
}
int BuscarCodigo(PRODUCTO vProducto[], char codigo[], int N)
{
    int i=0, posicion=-1;

    while(i<N && posicion == -1)
    {
        if(!(strcmpi(vProducto[i].codigo, codigo)))     // Si devuelve 0 --> falso || Si devuelve != 0 --> verdadero
            posicion = i;
        else
            i++;
    }
    return posicion;
}

int CargaDeProductos(PRODUCTO vProducto[], int N)
{
    char descripcion[31], codigo[6];
    int i=0, posicion;
    float precio;

    printf("----------CARGA DE PRODUCTOS----------");
    printf("\nDESCRIPCION ('FIN' para terminar): ");
    LeerTexto(descripcion, 31);
    while (i<N && (strcmpi(descripcion, "FIN")!=0))     //descripcion!="FIN" strcmpi(descripcion, "FIN")
    {
        strcpy(vProducto[i].descripcion, descripcion);  // Lo almacena
        printf("CODIGO (5 caracteres): ");
        LeerTexto(codigo, 6); // Input
        strcpy(vProducto[i].codigo, codigo); // Lo almacena
        printf("PRECIO: ");
        scanf("%f", &vProducto[i].precio); // Input
        getchar();
        i++;
        if (i<50)
        {
            do
            {
                printf("DESCRIPCION ('FIN' par terminar): ");
                LeerTexto(descripcion, 31);
                posicion = BuscarDescripcion(vProducto, descripcion, i);
                if(posicion != -1)
                    printf("DESCRIPCION ya registrada.\n");
            }while(posicion != -1);
        }
        else
            printf("Vector Lleno");
    }
    return i;
}

void CargaDeVentas(PRODUCTO vProducto[], int N)
{
    int i, posicion, cantidad;
    char codigo[6];

    for(i=0; i<N; i++)
        vProducto[i].cantidadDeUnidadesVendidas=0;
    printf("----------CARGA VENTA----------");
    printf("\nCANTIDAD PEDIDA ('0' para terminar): ");
    do
    {
        scanf("%d", &cantidad);
    }while(cantidad < 0);
    getchar();

    while(cantidad != 0)
    {
        do
        {
            printf("CODIGO del producto (5 caracteres): ");
            LeerTexto(codigo, 6); // Input
            posicion = BuscarCodigo(vProducto, codigo, N); // Lo busco en el vector
            if(posicion == -1)
                printf("CODIGO INVALIDO!\n");
        }while(posicion == -1);

        vProducto[posicion].cantidadDeUnidadesVendidas += cantidad;

        printf("Ingrese la CANTIDAD PEDIDA ('0' para terminar): ");
        do
        {
            scanf("%d", &cantidad);
        }while(cantidad < 0);
        getchar();

    }

    for(i=0; i<N; i++)
    {
        vProducto[i].importeTotalVendido = vProducto[i].precio * vProducto[i].cantidadDeUnidadesVendidas;
    }

}

void Listar(PRODUCTO vProducto[], int N)
{
    int i;

    printf("\n%12s%22s%18s","DESCRIPCION","CANTIDAD UNIDADES","IMPORTE TOTAL");
    printf("\n%30s%20s\n", "VENDIDAS",  "VENDIDO");
    for(i=0; i<N; i++)
        printf("\n%10s%18d%22.2f", vProducto[i].descripcion, vProducto[i].cantidadDeUnidadesVendidas, vProducto[i].importeTotalVendido);
}

