/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file tools.h (declaraciones funciones)
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

#include <iostream>
#include <string> //std::string
#include <fstream> //std::ofstream
#include <vector> //std::vector
#include <cstdlib> //exit

void usage(int& argc, char* argv[]); //Uso del programa
std::vector<int> fraciones_separadas(std::string fichero);
std::vector<int> fraciones_String_int(std::vector<std::string> fraciones_strings);
int minimo_comun_multiplo(int denominador1, int denominador2);

const std::string khelptext {"fichero_entrada: Fichero de texto conteniendo líneas con un par de números racionales: `a/b c/d` separados por un espacio fichero_salida:  Fichero de texto que contendrá líneas con las operaciones realizadas: `a/b + c/d = n/m`"};