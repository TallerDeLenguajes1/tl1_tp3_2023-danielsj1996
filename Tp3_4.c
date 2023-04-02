#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int cantidad;
    int i;
    printf("Indique la cantidad de nombres que desea ingresar: ");
    scanf("%d", &cantidad);
    
    char *nombres[cantidad]; // Declaración del vector de punteros a char


    // Pedir al usuario que ingrese los nombres y guardarlos en el vector
    for (i = 0; i < cantidad; i++)
    {
        printf("Ingrese el nombre %d: ", i + 1);

        
        nombres [i]= (char *)malloc((strlen(nombres[i])+1)*sizeof(char)); // Reservar memoria para el nombre
        scanf("%s", nombres[i]);
        
    }

    // Listar los nombres por pantalla
    printf("\nLos nombres ingresados son:\n");
    for (i = 0; i < cantidad; i++)
    {
          printf("%s\n", nombres[i]);
    }

    // Liberar la memoria reservada para los nombres
    for (i = 0; i < cantidad; i++)
    {
        free(nombres[i]);
    }

    return 0;
}
