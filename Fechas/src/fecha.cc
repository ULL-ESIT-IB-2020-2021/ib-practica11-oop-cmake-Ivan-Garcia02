/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file fecha.cc (definiciones)
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

///Imprime la fecha en el archivo elegido
void Fechas::printFecha(){  
  std::ofstream ficheroSalida {fichero_, std::ios::app};
  ficheroSalida << dia_ << '/' << mes_ << '/' << allo_ << std::endl;
}

///Indica si un año es bisiesto
void Fechas::esBisiesto(){
  if((allo_ % 4 == 0) && (allo_ % 100 != 0) || (allo_ % 400 == 0)) //Condición de bisiesto
    std::cout << allo_ << " Es Bisiesto" << std::endl;
  else
    std::cout << allo_ << " No es bisiesto" << std::endl;
}

///Cambien la fecha a la posterior
void Fechas::siguienteFecha(){
  dia_++;
  if (dia_ > 31){
    mes_++;
    Fechas::SetDia(1);
  }
  if (mes_ > 12){
    allo_++;
    Fechas::SetMes(1);
  }
}