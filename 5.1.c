#include <stdio.h>

int main()
{
    int variable, *puntero;

    puntero = &variable;
    *puntero = 10;
    printf("Direccion de la VARIABLE: %p", &variable);
    printf("\nDireccion del PUNTERO: %p", &puntero);
    printf("\nContenido de la VARIABLE: %d", variable);
    printf("\nContenido de la VARIABLE accediendo mediante el PUNTERO: %d", *puntero);
    printf("\nContenido del PUNTERO: %p", puntero);

    return 0;
}