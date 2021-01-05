/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file racional.h (declaraciones)
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
#ifndef RACIONAL_H
#define RACIONAL_H
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

class Racional {
 private:
  int numerador_{0};
  int denominador_{0};
  std::string ficheroSalida_{"Sample.txt"};
 
 public:
  Racional(); //constructor por defecto
  Racional(int numerador, int denominador, std::string ficheroSalida){ //Constructor especifico
    numerador_ = numerador;
    denominador_ = denominador;
    ficheroSalida_ = ficheroSalida;

  }
  int GetDenominador(){
    return denominador_;
  }
  void simplificar();
  void suma(Racional racional1, Racional racional2, int minimo_comun);
  void resta(Racional racional1, Racional racional2, int minimo_comun);
  void multiplicar(Racional racional1, Racional racional2);
  void dividir(Racional racional1, Racional racional2);
  void comparar(Racional racional1, Racional racional2);
  void print();

  
};

#endif