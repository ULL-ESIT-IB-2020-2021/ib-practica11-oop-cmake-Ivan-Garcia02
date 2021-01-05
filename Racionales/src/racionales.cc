/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file racionales.cc (programa principal)
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
 #include "tools.h"

int main(int argc, char* argv[]){
  usage(argc, argv);//Uso del programa

  std::string ficheroEntrada {argv[1]};
  std::string ficheroSalida {argv[2]};

  std::vector<int> fraciones = fraciones_separadas(ficheroEntrada);
  int numerador {fraciones[0]}, denominador {fraciones[1]};
  Racional racional1{numerador, denominador, ficheroSalida};

  numerador = fraciones[2];
  denominador = fraciones[3];
  Racional racional2{numerador, denominador, ficheroSalida};
  
  int minimo_comun = minimo_comun_multiplo(racional1.GetDenominador(), racional2.GetDenominador());

  Racional resultado {0, 0, ficheroSalida};
  resultado.suma(racional1, racional2, minimo_comun);
  resultado.print();

  resultado.resta(racional1, racional2, minimo_comun);
  resultado.print();

  resultado.multiplicar(racional1, racional2);
  resultado.print();

  resultado.dividir(racional1, racional2);
  resultado.print();

  resultado.comparar(racional1, racional2);

  return 0;
}