#include <stdio.h>
#include <string.h>

typedef struct
{
    int dni;
    char nombreYapellido[81];
    int nota1;
    int nota2;
    float promedio;
}sAlumno;

int main()
{
    sAlumno alumno;
    FILE * archivo;
    int i;
    archivo = fopen("ALUMNOS.dat", "wb");
    if(archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        getch();
        exit(1);
    }
    printf("Ingrese el DNI (FIN '0'): ");
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
        printf("Ingrese el DNI (FIN '0'): ");
        scanf("%d", &alumno.dni);
    }
    fclose(archivo);

    archivo = fopen("ALUMNOS.dat", "rb");
    if(archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        getch();    
        exit(1);
    }
    i = 0;
    fread(&alumno, sizeof(sAlumno), 1, archivo);
    while ( !feof(archivo) )
    {
        i++;
        fread(&alumno, sizeof(sAlumno), 1, archivo);
        printf("%d\n", alumno.dni);
        printf("%s\n", alumno.nombreYapellido);
        printf("%d\n", alumno.nota1);
        printf("%d\n", alumno.nota2);
        printf("%f\n", alumno.promedio);
    }
    fclose(archivo);
    return 0;
}