/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file complejo.h (declaraciones)
  * @author Iván García González alu0101388786@ull.edu.es
  * @date 7 Enero 2021
  * @brief Desarrolle un programa cliente complejos.cc que permita operar con números complejos y haga uso de la clase Complejo que diseñe. 
  *        La clase Complejo ha de contener al menos métodos que permitan (print()) imprimir un número complejo así como sumar (Add()) 
  *        y restar (Sub()) números complejos.
  * @bug No hay bugs conocidos
  * @see https://github.com/ULL-ESIT-IB-2020-2021/IB-P11-Classes-CMake/blob/master/Classes-CMake.md
  */
#ifndef COMPLEJO_H
#define COMPLEJO_H
#include <iostream>
#include <cmath>

class Complejo {
 private:
  int parteReal_{0};
  int parteImaginaria_{0};

 public:
  Complejo(int real, int imaginario){ //Constructor especifico
    parteReal_ = real;
    parteImaginaria_ = imaginario;
  }
  void suma(Complejo complejo1, Complejo complejo2);
  void resta(Complejo complejo1, Complejo complejo2);
  void multiplicacion(Complejo complejo1, Complejo complejo2);
  void division(Complejo complejo1, Complejo complejo2);
  void conjugado();
  void print();
};

#endif