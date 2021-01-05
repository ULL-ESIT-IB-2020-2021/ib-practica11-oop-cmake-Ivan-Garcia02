/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file tools.cc (funciones)
  * @author Iván García González alu0101388786@ull.edu.es
  * @date 7 Enero 2021
  * @brief Desarrolle un programa cliente racionales.cc que permita operar con números racionales y haga uso de la clase Racional que ha de diseñarse.
  *        La clase Racional incluirá al menos métodos para:
  *          Crear objetos de tipo Racional. Se debe implementar un constructor por defecto y uno parametrizado.
  *          Escribir (a fichero o a pantalla) un objeto de tipo Racional.
  *          Leer (por teclado o desde fichero) un objeto de tipo Racional.
  *          Sumar dos objetos de tipo Racional.
  *          Restar dos objetos de tipo Racional.
  *          Multiplicar dos objetos de tipo Racional.
  *          Dividir dos objetos de tipo Racional.
  *          Comparar objetos de tipo Racional.
  *        El programa ha de permitir leer un fichero de texto en el que figuran pares de números racionales separados por espacios.
  *        y para cada par de números racionales, el programa ha de imprimir en otro fichero de salida todas las operaciones posibles
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
  else if (argc != 3){
    std::cout << "Modo de uso: " <<argv[0] << " fichero_entrada fichero_salida" << std::endl; 
    std::cout << "Pruebe "<< argv[0] << " --help para más información." << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/**
 * Lectura de un fichero y conversion de su contenido en un vector de enteros
 *
 * @param nombre del fichero de entrada
 * @return vector de enteros
 */
std::vector<int> fraciones_separadas(std::string fichero){
  std::vector<std::string> fraciones_strings;
  std::vector<int> fraciones_int;
  std::string numero;

  std::ifstream ficheroEntrada {fichero};
  while (getline(ficheroEntrada, numero, '/')){
    fraciones_strings.push_back(numero);
    //std::cout << nombre << std::endl;
    if (getline(ficheroEntrada, numero, ' ')){
      fraciones_strings.push_back(numero);
      //std::cout << nombre << std::endl;
    }
  }
  fraciones_int = fraciones_String_int(fraciones_strings);
  return fraciones_int;

}

/**
 * Conversion de un vector de string en uno de enteros
 *
 * @param vector de strings
 * @return vector de enteros
 */
std::vector<int> fraciones_String_int(std::vector<std::string> fraciones_strings){
  std::vector<int> fraciones_int;
  std::string numero;
  int numero_entero;
  for (int i{0}; i < fraciones_strings.size(); i++){
    numero = fraciones_strings[i];
    numero_entero = std::stoi(numero);
    fraciones_int.push_back(numero_entero);
  }
  return fraciones_int;
}

/**
 * minimo comun multiplo de dos denominadores
 *
 * @param denominadores de las fraciones
 * @return el minimo comun multiplo
 */
int minimo_comun_multiplo(int denominador1, int denominador2){
  int mayor {0};
  if (denominador1 > denominador2){
    mayor = denominador1;
  }
  else {
    mayor = denominador2;
  }
  int mcm = mayor;
  while((mcm % denominador1 != 0) || (mcm % denominador2 != 0)){
    mcm += 1;
  }
  return mcm;
}