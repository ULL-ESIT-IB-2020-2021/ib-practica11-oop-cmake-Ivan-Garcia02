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
#include "tools.h"

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