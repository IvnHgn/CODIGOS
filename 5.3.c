#include <stdio.h>
#include <stdlib.h>

void IngresarVariables(int*, float*, char*);

int main()
{
    int variable1;
    float variable2;
    char variable3; 
    
    IngresarVariables(&variable1, &variable2, &variable3);    
    printf("\nVARIABLE ENTERA: %d", variable1);
    printf("\nVARIABLE FLOTANTE: %.2f", variable2);
    printf("\nVARIABLE CARACTER: %c\n", variable3);
    system("pause");
    return 0;
}

void IngresarVariables(int *puntero1, float *puntero2, char *puntero3)
{
    printf("Ingrese un valor ENTERO: ");
    scanf("%d", puntero1);
    printf("Ingrese un valor FLOTANTE: ");
    scanf("%f", puntero2);
    printf("Ingrese un valor CARACTER: ");
    getchar();
    scanf("%c", puntero3);
}