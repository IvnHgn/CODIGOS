#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1=10, num2=5, *puntero1, *puntero2;

    puntero1 = &num1;
    puntero2 = &num2;
    printf("Resultado de la SUMA de las VARIABLES: %d\n", *puntero1 + *puntero2);
    system("pause");
    return 0;
}