/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file tools.cc (funciones)
  * @author Iván García González alu0101388786@ull.edu.es
  * @date 7 Enero 2021
  * @brief Desarrolle una clase Fecha que permita representar y gestionar fechas. Incorpore en la clase los miembros de datos 
  *        y métodos que considere adecuados para la finalidad que se persigue en este ejercicio. 
  *        Incluya un método que permita determinar si el año correspondiente a una fecha es un año bisiesto o no. 
  *        Realice un programa cliente fechas.cc que tome como parámetro una fecha, un número y un nombre de fichero.
  *        El programa deberá imprimir en el fichero de salida (tercer parámetro) las N (segundo parámetro) fechas cronológicamente 
  *        posteriores a la introducida (primer parámetro) con una separación de un día entre fechas sucesivas.
  * @bug No hay bugs conocidos
  * @see https://github.com/ULL-ESIT-IB-2020-2021/IB-P11-Classes-CMake/blob/master/Classes-CMake.md
  */
#include "tools2.h"

/**
 * Uso del programa.
 *
 * @param valores de entrada argc y argv.
 * @return nothing.
 */
void usage(int& argc, char* argv[]){ //Uso del programa  
  if (argc == 2){
    std::string parameter {argv [1]};

    if (parameter == "--help"){
      std::cout << khelptext << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
  else if (argc != 6){
    std::cout << "Modo de uso: " <<argv[0] << " dd mm aa N fichero_salida.txt" << std::endl; 
    std::cout << "Pruebe "<< argv[0] << " --help para más información." << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/**
 * Comprobar fecha.
 *
 * @param valores dia mes  año.
 * @return nothing.
 */
void comprobarFecha(int& dia, int& mes, int& anllo){
  if((mes < 1) || (mes > 12)){
    std::cout << "Formato de fecha erroneo el mes no puede ser: " << mes << std::endl;
    exit (EXIT_SUCCESS);
  }

  if(dia < 1){
    std::cout << "Formato de fecha erroneo el dia no puede ser: " << dia << std::endl;
    exit (EXIT_SUCCESS);
  }

  if((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)){
    if(dia > 31){
      std::cout << "Formato de fecha erroneo el dia no puede ser: " << dia << std::endl;
      exit (EXIT_SUCCESS);
    }
  }

  if((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)){
    if(dia > 30){
      std::cout << "Formato de fecha erroneo el dia no puede ser: " << dia << std::endl;
      exit (EXIT_SUCCESS);
    }
  }

  if(mes == 2){
    if(esBisiesto(anllo)){
      if(dia > 29){
        std::cout << "Formato de fecha erroneo el dia no puede ser: " << dia << std::endl;
        exit (EXIT_SUCCESS);
      }
    }
    else{
      if(dia > 28){
        std::cout << "Formato de fecha erroneo el dia no puede ser: " << dia << std::endl;
        exit (EXIT_SUCCESS);
      }
    }
  }
}

/**
 * año bisiesto.
 *
 * @param valor de año.
 * @return si un año es bisiesto o no en boleano.
 */
bool esBisiesto(int& allo){
  if((allo % 4 == 0) && (allo % 100 != 0) || (allo % 400 == 0)) //Condición de bisiesto
    return true;
  else
    return false;
}