/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file racional.cc (definiciones)
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
#include "racional.h"

void Racional::simplificar(){
  for (int i = denominador_ * numerador_; i > 0; i--) {
    if ((fmod(denominador_, i) == 0) && (fmod(numerador_, i) == 0)){  
      numerador_ /= i;  
      denominador_ /= i;  
    }        
  }
  while((fmod(numerador_, 10) == 0) && (fmod(denominador_, 10) == 0)){
    numerador_ /= 10;
    denominador_ /= 10;
  }
}

void Racional::suma(Racional racional1, Racional racional2, int minimo_comun){ //Suma dos objetos racionales 
  numerador_ = (racional1.numerador_ * minimo_comun / racional1.denominador_) + (racional2.numerador_ * minimo_comun / racional2.denominador_);
  denominador_ = minimo_comun;
  simplificar();

  std::cout << racional1.numerador_ << "/" << racional1.denominador_ << " + " << racional2.numerador_ << "/" << racional2.denominador_ << " = ";
  std::ofstream ficheroSalida {ficheroSalida_, std::ios::app};
  ficheroSalida << racional1.numerador_ << "/" << racional1.denominador_ << " + " << racional2.numerador_ << "/" << racional2.denominador_ << " = ";
}

void Racional::resta(Racional racional1, Racional racional2, int minimo_comun){//Resta dos objetos racionales
  numerador_ = (racional1.numerador_ * minimo_comun / racional1.denominador_) - (racional2.numerador_ * minimo_comun / racional2.denominador_);
  denominador_ = minimo_comun;
  simplificar();

  std::cout << racional1.numerador_ << "/" << racional1.denominador_ << " - " << racional2.numerador_ << "/" << racional2.denominador_ << " = ";
  std::ofstream ficheroSalida {ficheroSalida_, std::ios::app};
  ficheroSalida << racional1.numerador_ << "/" << racional1.denominador_ << " - " << racional2.numerador_ << "/" << racional2.denominador_ << " = ";
}


void Racional::multiplicar(Racional racional1, Racional racional2){//Multiplica dos objetos racionales
  numerador_ = racional1.numerador_ * racional2.numerador_;
  denominador_ = racional1.denominador_ * racional2.denominador_;
  simplificar();

  std::cout << racional1.numerador_ << "/" << racional1.denominador_ << " * " << racional2.numerador_ << "/" << racional2.denominador_ << " = ";
  std::ofstream ficheroSalida {ficheroSalida_, std::ios::app};
  ficheroSalida << racional1.numerador_ << "/" << racional1.denominador_ << " * " << racional2.numerador_ << "/" << racional2.denominador_ << " = ";
}

void Racional::dividir(Racional racional1, Racional racional2){//Divide dos objetos racionales
  numerador_ = racional1.numerador_ * racional2.denominador_;
  denominador_ = racional1.denominador_ * racional2.numerador_;
  simplificar();
  
  std::cout << racional1.numerador_ << "/" << racional1.denominador_ << " / " << racional2.numerador_ << "/" << racional2.denominador_ << " = ";
  std::ofstream ficheroSalida {ficheroSalida_, std::ios::app};
  ficheroSalida << racional1.numerador_ << "/" << racional1.denominador_ << " / " << racional2.numerador_ << "/" << racional2.denominador_ << " = ";
}

void Racional::comparar(Racional racional1, Racional racional2){//Compara dos objetos racionales
  const double racional_1 = racional1.numerador_ / racional1.denominador_;
  const double racional_2 = racional2.numerador_ / racional2.denominador_;
  if (racional_1 > racional_2){
    std::cout << racional1.numerador_ << "/" << racional1.denominador_ << " > " << racional2.numerador_ << "/" << racional2.denominador_ << std::endl;
    std::ofstream ficheroSalida {ficheroSalida_, std::ios::app};
    ficheroSalida << racional1.numerador_ << "/" << racional1.denominador_ << " > " << racional2.numerador_ << "/" << racional2.denominador_ << std::endl;
  }
  else{
    std::cout << racional1.numerador_ << "/" << racional1.denominador_ << " < " << racional2.numerador_ << "/" << racional2.denominador_ << std::endl;
    std::ofstream ficheroSalida {ficheroSalida_, std::ios::app};
    ficheroSalida << racional1.numerador_ << "/" << racional1.denominador_ << " < " << racional2.numerador_ << "/" << racional2.denominador_ << std::endl;
  }
}

void Racional::print(){ //imprime tanto en pantallo como en el fichero de salida
  std::cout << numerador_ << "/" << denominador_ << std::endl;

  std::ofstream ficheroSalida {ficheroSalida_, std::ios::app};
  ficheroSalida << numerador_ << "/" << denominador_ << std::endl;
}
