#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
};
struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    struct Producto *Productos;  // El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
};

float calcularCostoProducto(struct Producto p);

int main()
{
    int cantidadClientes;

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);
    srand(time(NULL));
    int rand();

    struct Cliente *clientes = (struct Cliente *)malloc(cantidadClientes * sizeof(struct Cliente));

    for (int i = 0; i < cantidadClientes; i++)
    {
        float CostoFinal = 0;
        printf("Cliente Nro. %d\n", i + 1);
        printf("Ingrese el nombre del cliente: ");
        char nombre_cliente[100];
        scanf("%s", nombre_cliente);
        clientes[i].ClienteID = i + 1;
        clientes[i].NombreCliente = (char *)malloc(strlen(nombre_cliente) * sizeof(char));
        strcpy(clientes[i].NombreCliente, nombre_cliente);
        clientes[i].CantidadProductosAPedir = rand() % 5 + 1;
        clientes[i].Productos = (struct Producto *)malloc(clientes[i].CantidadProductosAPedir * sizeof(struct Producto));
        printf("Cantidad de productos a pedir: %d\n", clientes[i].CantidadProductosAPedir);

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = rand() % 10 + 1;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
            clientes[i].Productos[j].PrecioUnitario = rand() % 91 + 10;
        }
    }

    for (int i = 0; i < cantidadClientes; i++)
    {
        printf("\nCliente %d: %s\n", clientes[i].ClienteID, clientes[i].NombreCliente);
        float totalPagar = 0;
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("Producto cargado nro. %d\n", clientes[i].Productos[j].ProductoID);
            printf("Cantidad: %d\n", clientes[i].Productos[j].Cantidad);
            printf("Tipo de producto: %s\n", clientes[i].Productos[j].TipoProducto);
            printf("Precio unitario: %.2f\n", clientes[i].Productos[j].PrecioUnitario);
            float precioFinal = calcularCostoProducto(clientes[i].Productos[j]);
            printf("Costo del producto: %.2f\n\n", precioFinal);
            totalPagar += precioFinal;
        }
        printf("Total a pagar por el cliente: %.2f\n\n", totalPagar);
    }
        free(clientes);
    return 0;
}

float calcularCostoProducto(struct Producto p)
{
    float calculo = p.Cantidad * p.PrecioUnitario;
    return calculo;
}
