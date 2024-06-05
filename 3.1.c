#include <stdio.h>
#include <string.h>

void IngresarFrase();
int  ContadorDePalabras();

int main()
{
    char vFrase[500];
    int contador;

    IngresarFrase(vFrase, 500);
    contador = ContadorDePalabras(vFrase);
    printf("La cantidad de palabras que hay en la frase es: %d", contador);
    return 0;
}

void IngresarFrase(char vFrase[], int N)
{
    int i=0;
    printf("\nIngrese una frase: ");
    fgets(vFrase, N, stdin);
    while (vFrase[i]!='\0')
    {
        if (vFrase[i]=='\n')
            vFrase[i]='\0';
        else
            i++;
    }
}

int ContadorDePalabras(char vFrase[])
{
    int contador=0, i=0;
    
    if (vFrase[0] != ' ') // Considerar caso especial primer palabra 
        contador++;
    while(vFrase[i] != '\0') // Contar palabras separadas por mas de un espacio consecutivo
    {
        if(vFrase[i] == ' ' && vFrase[i+1] != ' ') 
        {
            contador++;
            i++;
        } 
        else    
            i++;
    }
    return contador;
}