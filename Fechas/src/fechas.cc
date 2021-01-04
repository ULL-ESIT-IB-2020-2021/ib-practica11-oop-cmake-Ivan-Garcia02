/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file fechas.cc (programa principal)
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

 #include "fecha.h"
 #include "tools.h"

int main(int argc, char* argv[]){
  usage(argc, argv); //Uso del programa

  std::string transforma_1 {argv[1]}, transforma_2 {argv[2]}, transforma_3 {argv[3]};
  std::string transforma_N {argv[4]};
  std::string ficheroSalida {argv[5]};
  int dia = std::stoi(transforma_1);
  int mes = std::stoi(transforma_2);
  int allo = std::stoi(transforma_3);
  int numero_repeticiones = std::stoi(transforma_N);

  Fechas fecha;
  fecha.SetDia(dia);
  fecha.SetMes(mes);
  fecha.SetAllo(allo);
  fecha.SetFichero(ficheroSalida);

  fecha.printFecha();

  for (int i {0}; i < numero_repeticiones; i++){
    fecha.siguienteFecha();
    fecha.printFecha();
  }
  
  return 0;
}