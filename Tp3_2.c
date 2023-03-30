#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **Nombres_Apellido = (char **)malloc(5 * sizeof(char *)); // Reservamos memoria para un vector de 5 punteros a char con doble puntero|
    
    for (int i = 0; i < 5; i++)
    {
        printf("Escriba el nombre completo de la persona #%d: \n",i+1);
        Nombres_Apellido[i] = (char *)malloc(50 * sizeof(char));   // Reservamos memoria para un string de hasta 50 caracteres con puntero simple
        fgets(Nombres_Apellido[i], 50, stdin);                  // Leemos el nombre del usuario y lo almacenamos en el vector de punteros
        Nombres_Apellido[i][strlen(Nombres_Apellido[i]) - 1] = '\0';     // Eliminamos el salto de línea del final del string
        
    }

    printf("\nLos nombres ingresados son:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Nombre y apellido %d:  %s %s\n", i + 1, Nombres_Apellido[i]); // Imprimimos cada uno de los nombres almacenados en el vector de punteros
    }

    // Liberamos la memoria reservada para cada uno de los strings
    for (int i = 0; i < 5; i++)
    {
        free(Nombres_Apellido[i]);
    }

    // Liberamos la memoria reservada para el vector de punteros
    free(Nombres_Apellido);

    return 0;
}
