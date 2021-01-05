/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file complejo.cc (definiciones)
  * @author Iván García González alu0101388786@ull.edu.es
  * @date 7 Enero 2021
  * @brief Desarrolle un programa cliente complejos.cc que permita operar con números complejos y haga uso de la clase Complejo que diseñe. 
  *        La clase Complejo ha de contener al menos métodos que permitan (print()) imprimir un número complejo así como sumar (Add()) 
  *        y restar (Sub()) números complejos.
  * @bug No hay bugs conocidos
  * @see https://github.com/ULL-ESIT-IB-2020-2021/IB-P11-Classes-CMake/blob/master/Classes-CMake.md
  */
#include "complejo.h"

void Complejo::suma(Complejo complejo1, Complejo complejo2){ //suma dos objetos complejos
  parteReal_ = complejo1.parteReal_ + complejo2.parteReal_;
  parteImaginaria_ = complejo1.parteImaginaria_ + complejo2.parteImaginaria_;
}

void Complejo::resta(Complejo complejo1, Complejo complejo2){ //resta dos objetos complejos
  parteReal_ = complejo1.parteReal_ - complejo2.parteReal_;
  parteImaginaria_ = complejo1.parteImaginaria_ - complejo2.parteImaginaria_;
}

void Complejo::multiplicacion(Complejo complejo1, Complejo complejo2){ //multiplica dos objetos complejos
  parteReal_ = (complejo1.parteReal_ * complejo2.parteReal_) - (complejo1.parteImaginaria_ * complejo2.parteImaginaria_);
  parteImaginaria_ = (complejo1.parteReal_ * complejo2.parteImaginaria_) + (complejo1.parteImaginaria_ * complejo2.parteReal_);
}

void Complejo::division(Complejo complejo1, Complejo complejo2){ //divide dos objetos complejos
  int denominador = (pow(complejo2.parteReal_, 2)) + (pow(complejo2.parteImaginaria_, 2));
  parteReal_ = (complejo1.parteReal_ * complejo2.parteReal_) + (complejo1.parteImaginaria_ * complejo2.parteImaginaria_);
  parteImaginaria_ = (complejo1.parteImaginaria_ * complejo2.parteReal_) - (complejo1.parteReal_ * complejo2.parteImaginaria_);

  print();
  std::cout << "----------" << std::endl << "   " <<denominador << std::endl;
}

void Complejo::conjugado(){ //da el conjugado de un complejo y lo imprime en pantalla
  parteImaginaria_ *= -1;
  print();
}

void Complejo::print(){ //imprime en pantalla el numero complejo
  std::cout << parteReal_;
  if (parteImaginaria_ >= 0){
    std::cout << " + " << parteImaginaria_ << " i" << std::endl;
  }
  else {
    std::cout << " " << parteImaginaria_ << " i" << std::endl;
  }
}