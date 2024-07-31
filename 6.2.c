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
    FILE *fAlumnos, *fPromocionados, *fCursado, *fReprobados;
    sAlumno alumno;

    fAlumnos = fopen("ALUMNOS.dat", "rb");
    fPromocionados = fopen("PROMOCIONADOS.dat", "wb");
    fCursado = fopen("CURSADO.dat", "wb");
    fReprobados = fopen("REPROBADOS.dat", "wb");
    if(fAlumnos == NULL || fPromocionados == NULL || fCursado == NULL || fReprobados == NULL)
    {
        printf("Error al abrir el archivo.");
        getch();
        exit(1);
    }
    fread(&alumno, sizeof(sAlumno), 1, fAlumnos);
    while(!feof(fAlumnos))
    {
        if(alumno.nota1>=7 && alumno.nota2>=7)
            fwrite(&alumno, sizeof(sAlumno), 1, fPromocionados);
        else
            if(alumno.nota1>=4 && alumno.nota2>=4)
                fwrite(&alumno, sizeof(sAlumno), 1, fCursado);
            else
                fwrite(&alumno, sizeof(sAlumno), 1, fReprobados);

        fread(&alumno, sizeof(sAlumno), 1, fAlumnos);
    }
    fclose(fAlumnos);
    fclose(fPromocionados);
    fclose(fCursado);
    fclose(fReprobados);

    fPromocionados = fopen("PROMOCIONADOS.dat", "rb");
    fCursado = fopen("CURSADO.dat", "rb");
    fReprobados = fopen("REPROBADOS.dat", "rb");
    if(fPromocionados == NULL || fCursado == NULL || fReprobados == NULL)
    {
        printf("Error al abrir el archivo.");
        getch();
        exit(1);
    }
    printf("------ALUMNOS PROMOCIONADOS------\n");
    LECTURA(fPromocionados);
    printf("------ALUMNOS CURSADO------\n");
    LECTURA(fCursado);
    printf("------ALUMNOS REPROBADOS------\n");
    LECTURA(fReprobados);

    fclose(fPromocionados);
    fclose(fCursado);
    fclose(fReprobados);
    return 0;
}

void LECTURA(FILE * archivo)
{
    sAlumno alumno;

    fread(&alumno, sizeof(sAlumno), 1, archivo);
    while(!feof(archivo))
    {
        printf("DNI: %d\n", alumno.dni);
        printf("NOMBRE Y APELLIDO: %s\n", alumno.nombreYapellido);
        printf("NOTA 1: %d\n", alumno.nota1);
        printf("NOTA 2: %d\n", alumno.nota2);
        printf("PROMEDIO: %.2f\n", alumno.promedio);
        fread(&alumno, sizeof(sAlumno), 1, archivo);
    }

}