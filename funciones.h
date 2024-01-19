#ifndef funciones_H_INCLUDED
#define funciones_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *farmacia;

struct datosmedicina
{
    char nombre[20];
    char precio[20];
}fardat;

void crear()
{
    char direccion [] = "D:\\fardat.txt";
    char rpt;
    farmacia = fopen(direccion, "wt");
    if (farmacia == NULL)
    {
        printf("Error al tratar de crear el archivo");
        return 1;
    }
    printf("\n\t: Creacion de Inventario: \n");
    fprintf(farmacia,"\t : Inventario : \n");
    do
    {
        fflush(stdin);
        printf("\nNombre: "); scanf("%s",fardat.nombre);
        printf("\nPrecio: "); scanf("%s",fardat.precio);

        fprintf(farmacia,"\n\nNombre : ");
        fwrite(fardat.nombre,1,strlen(fardat.nombre),farmacia);

        fprintf(farmacia,"\nPrecio : ");
        fwrite(fardat.precio,1,strlen(fardat.precio),farmacia);
        
        printf("Desea agregar mas medicinas (s) : ");
        scanf("%c",&rpt);
    } while (rpt == 's');
    fclose(farmacia);   
}
void agregar()
{
    char direccion [] = "D:\\fardat.txt";
    char rpt;
    farmacia = fopen(direccion, "at");   
    if (farmacia == NULL)
    {
        printf("Error al tratar de crear el archivo");
        return 1;
    }
    printf("\n\t: Agregando medicinas : \n");
    do
    {
        fflush(stdin);
        printf("\nNombre: "); scanf("%s",fardat.nombre);
        printf("\nPrecio: "); scanf("%s",fardat.precio);

        fprintf(farmacia,"\n\nNombre : ");
        fwrite(fardat.nombre,1,strlen(fardat.nombre),farmacia);

        fprintf(farmacia,"\nPrecio : ");
        fwrite(fardat.precio,1,strlen(fardat.precio),farmacia);

        printf("Desea agregar mas medicinas (s) : ");
        scanf("%c",&rpt);
    } while (rpt == 's');
    fclose(farmacia);   
}
void visualizar()
{
    char direccion [] = "D:\\fardat.txt";
    int c;
    farmacia = fopen(direccion, "r");   
    if (farmacia == NULL)
    {
        printf("Error al tratar de crear el archivo");
        return 1;
    }
    while ((c=fgetc(farmacia))!=EOF)
    {
        if(c =='\n')
        {
            printf("\n");
        }
        else
        {
            putchar(c);
        }
    }
    
    fclose(farmacia);   
}

#endif 
