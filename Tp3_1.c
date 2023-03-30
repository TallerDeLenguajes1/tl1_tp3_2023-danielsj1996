#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int matriz[5][12];
    int i,j,max_valor,min_valor,max_anio,min_anio;
    char *min_mes,*max_mes;
  
    float promedio_ano=0; 
    
     char* meses[12] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"}; // nombres de los meses


    // a. Cargando la matriz con valores aleatorios
    srand(time(NULL));
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 12; j++) {
            matriz[i][j] = rand() % 40001 + 10000; // valores entre 10000 y 50000
        }
    }

    // b. Mostrando los valores cargados


    printf("Valores cargados:\n");
    for(i = 0; i < 5; i++) {

            printf("Anio %d: |",i+1);
        for(j = 0; j < 12; j++) {
            printf("%s:",meses[j]);
            printf(" %d |", matriz[i][j]);
        }
        printf("\n");
    }


    // c. Calculando el promedio de ganancia por año
    printf("\nPromedio de ganancia por anio:\n");
    for(i = 0; i < 5; i++) {
        
        for(j = 0; j < 12; j++) {
            promedio_ano += matriz[i][j];
        }
        promedio_ano /= 12;
        printf("Anio %d: %.2f\n", i+1, promedio_ano);
    }

    // d. Encontrando el valor máximo y mínimo
    max_valor = matriz[0][0];
    min_valor = matriz[0][0];
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 12; j++) {
            if(matriz[i][j] > max_valor) {
                max_valor = matriz[i][j];
                max_anio = i+1;
                max_mes = meses[j];
            }
            if(matriz[i][j] < min_valor) {
                min_valor = matriz[i][j];
                min_anio = i+1;
                min_mes = meses[j];
            }
        }
    }
    printf("\nValor Maximo: %d (Anio: %d, Mes: %s)", max_valor, max_anio, max_mes);
    printf("\nValor Minimo: %d (Anio: %d, Mes: %s)", min_valor, min_anio, min_mes);

    return 0;
}



