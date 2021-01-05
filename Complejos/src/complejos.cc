/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file complejos.cc (programa principal)
  * @author Iván García González alu0101388786@ull.edu.es
  * @date 7 Enero 2021
  * @brief Desarrolle un programa cliente complejos.cc que permita operar con números complejos y haga uso de la clase Complejo que diseñe. 
  *        La clase Complejo ha de contener al menos métodos que permitan (print()) imprimir un número complejo así como sumar (Add()) 
  *        y restar (Sub()) números complejos.
  * @bug No hay bugs conocidos
  * @see https://github.com/ULL-ESIT-IB-2020-2021/IB-P11-Classes-CMake/blob/master/Classes-CMake.md
  */

 #include "complejo.h"

int main(){
  Complejo complejo1{4, 5}, complejo2{7, -8};
  Complejo resultado{0, 0};

  std::cout << "Suma de los complejo: " << std::endl;
  resultado.suma(complejo1, complejo2);
  resultado.print();
  std::cout << "Resta de los complejo: "<< std::endl;
  resultado.resta(complejo1, complejo2);
  resultado.print();
  std::cout << "Multiplicacion de los complejo: "<< std::endl;
  resultado.multiplicacion(complejo1, complejo2);
  resultado.print();
   std::cout << "Division de los complejo: "<< std::endl;
  resultado.division(complejo1, complejo2);

  std::cout << "Conjugado del primer y segundo complejo:" << std::endl;
  complejo1.conjugado();
  complejo2.conjugado();

  return 0;
}