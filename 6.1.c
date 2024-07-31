#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
    int dni;
    char nombreYapellido[81];
    int nota1;
    int nota2;
    float promedio;
}sAlumno;

void LECTURA(FILE *);

int main()
{
    sAlumno alumno;
    FILE * archivo;

    archivo = fopen("ALUMNOS.dat", "wb");
    if(archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        getch();
        exit(1);
    }
    printf("DNI (FIN '0'): ");
    scanf("%d", &alumno.dni);
    while(alumno.dni != 0)
    {
        getchar();
        printf("NOMBRE Y APELLIDO: ");
        gets(alumno.nombreYapellido);
        printf("NOTA 1: ");
        scanf("%d", &alumno.nota1);
        printf("NOTA 2: ");
        scanf("%d", &alumno.nota2);
        alumno.promedio = (alumno.nota1 + alumno.nota2) / 2;
        fwrite(&alumno, sizeof(sAlumno), 1,archivo);
        printf("DNI (FIN '0'): ");
        scanf("%d", &alumno.dni);
    }
    fclose(archivo);
    printf("-------LECTURA-------\n");
    LECTURA(archivo);
    return 0;
}

void LECTURA(FILE * archivo)
{
    sAlumno alumno;
    archivo = fopen("ALUMNOS.dat", "rb");
    if(archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        getch();    
        exit(1);
    }
    fread(&alumno, sizeof(sAlumno), 1, archivo);
    while ( !feof(archivo) )
    {
        printf("DNI: %d\n", alumno.dni);
        printf("NOMBRE Y APELLIDO: %s\n", alumno.nombreYapellido);
        printf("NOTA 1: %d\n", alumno.nota1);
        printf("NOTA 2: %d\n", alumno.nota2);
        printf("PROMEDIO: %.2f\n", alumno.promedio);
        fread(&alumno, sizeof(sAlumno), 1, archivo);
    }
    fclose(archivo); 
}
