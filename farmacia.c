#include <stdio.h>
#include <string.h>
FILE *inventario;
FILE *receta;
struct datos_medicina
{
    char nombre[20];
    char gramaje[10];
    char precio[10];
}datos;

int main()
{
    char addressinventario[]= "D:\\Nueva carpeta\\inventario.txt";
    char addressreceta[]= "D:\\Nueva carpeta\\receta.txt";

    int menu = 0;

    inventario = fopen(addressinventario,"r");
    if (inventario == NULL)
    {
        inventario = fopen(addressinventario,"a+");
    }

    receta = fopen(addressreceta,"r");
    if (receta == NULL)
    {
        receta = fopen(addressreceta,"a+");
    }

    while (menu != 4)
    {
        printf("\n1. Mostrar el inventario\n2. Modificar el inventario\n3. Receta medica\n4. Salir\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            break;
        case 2:
            printf("\n1. Añadir medicamento\n2. Modificar medicamento\n3. Eliminar medicamento\n");
            scanf("%d",&menu);
            switch (menu)
            {
            case 1:
                fflush(stdin);
                printf("\nNombre del medicamento : "); gets(datos.nombre);
                printf("\nGramaje del medicamento : "); gets(datos.gramaje);
                printf("\nPrecio del medicamento : "); gets(datos.precio);
                fwrite(datos.nombre,1,strlen(datos.nombre),inventario);
                fwrite(datos.gramaje,1,strlen(datos.gramaje),inventario);
                fwrite(datos.precio,1,strlen(datos.precio),inventario);
                break;
            case 2:
            break;
            case 3:
            break;
            default:
            printf("Ingrese una opcion correcta");
                break;
            }
            break;
        case 3:
            
            break;        
        case 4:
            break;
        default:
            printf("Ingrese una opcion valida");
            break;
        }
    }
    fclose(inventario);
    return 0;
}