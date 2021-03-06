#ifndef VEHICULO_C
#define VEHICULO_C

#include "../helpers/EstadoVehiculo.c"
#include "Ciudad.h"
#include "Fecha.c"

typedef struct vehiculo {
        char matricula [6];
        Fecha fechaFabricacion;
        float capacidad;
        EstadoVehiculo estadoVehiculo;
} Vehiculo;



int validarMatricula(char* matricula, int tipo){
  if(strlen(matricula) != 6){
    if(tipo == 1){
      printf("ERROR: la matricula esta compuesta de 6 caracteres\n");
    }
    return 0;
  }
  if (isdigit(matricula [0]) == 0 || isdigit(matricula [1]) == 0 ) {
    if(tipo == 1){
    printf("ERROR: Los dos primeros caracteres tienen que ser numericos\n");
    }
    return 0;
  }
  if (isalpha(matricula [2]) == 0 || isalpha(matricula [3]) == 0){
    if (tipo == 1){
      printf("ERROR: Los dos caracteres del medio tienen que ser alfabeticos\n");
    }
    return 0;
  }
  if (isdigit(matricula [4]) == 0 || isdigit(matricula [5]) == 0) {
    if (tipo == 1) {
    printf("Los dos ultimos caracteres tiene que ser numericos\n");
    }
    return 0;
  }
  return 1;
}

int tamanoVehiculos(Vehiculo vehiculos[]){
  for (int i = 0; i < 10; i++){
    if (validarMatricula(vehiculos[i].matricula, 0) == 0){
      return i;
    }
  }
  return 0;
}

int validarMatriculaRepetida(Vehiculo vehiculos[], char *matricula){
  for(int i = 0; i < tamanoVehiculos(vehiculos); i++){
    if(strcmp(vehiculos[i].matricula, matricula) == 0){
        printf("ERROR: La matricula ingresada es repetida\n");
        return 0;
    }
  }
    return 1;
}

int leerEstadoVehiculo(){
  int opcion;
  printf("Digite cualquiera de las siguientes opciones\n");
  printf("1 => DISPONIBLE \n\n");
  printf("2 => EN_CARGA \n\n");
  printf("3 => TRANSPORTANDO \n\n");
  printf("4 => REGRESO \n\n");
  printf("0 => AVERIADO\n");
  do {
    printf("Ingrese su opcion:\n");
    scanf("%d", &opcion);
    if(opcion < 0 || opcion > 4){
      printf("La opcion es invalida vuelva a ingresar su opcion\n");
    }
  } while(opcion < 0 || opcion > 4);
  return opcion;
}
Vehiculo leerVehiculo(){

        Vehiculo vehiculo;

        do{
        leerString("Matricula", vehiculo.matricula);
      }while(validarMatricula(vehiculo.matricula, 1) == 0);

        do {
                leerFlotante("Capacidad", &vehiculo.capacidad);
                if (vehiculo.capacidad > 20 || vehiculo.capacidad < 1) {
                  printf("El valor de la capacidad tiene que ser entre 1 a 20 (KG)\n" );
                }
        } while(vehiculo.capacidad > 20 || vehiculo.capacidad < 1);
        vehiculo.fechaFabricacion = leerFecha();
        vehiculo.estadoVehiculo = leerEstadoVehiculo();
        return vehiculo;
}

 void imprimirVehiculo(Vehiculo vehiculo){
   printf("El numero de la matricula es: %s \n",vehiculo.matricula);
   printf("El 80 porciento de la carga maxima del vehiculo es %2f\n",vehiculo.capacidad);
   printf("El dia en el que fue fabrciado es: %d\n",vehiculo.fechaFabricacion.dia);
   printf("El mes en el que fue fabrciado es: %d\n",vehiculo.fechaFabricacion.mes);
   printf("El ano en el que fue fabrciado es: %d\n",vehiculo.fechaFabricacion.ano);
   printf("El valor es %s", getEstadoVehiculo(vehiculo.estadoVehiculo));

 }




#endif
