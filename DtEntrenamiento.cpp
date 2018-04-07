/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtEntrenamiento.cpp
 * Author: mcurbelo
 * 
 * Created on March 19, 2018, 3:34 PM
 */

#include "DtEntrenamiento.h"
#include <sstream>
void DtEntrenamiento::setEnRambla(bool enRambla){
    this->enRambla = enRambla;
}

bool DtEntrenamiento::getEnRambla(){
    return this->enRambla;
}
DtEntrenamiento::DtEntrenamiento() {
}
DtEntrenamiento::DtEntrenamiento(int id, string nombre, Turno turno, bool enRambla){
    DtClase(id, nombre, turno);
    this->enRambla = enRambla;
}
DtEntrenamiento::DtEntrenamiento(const DtEntrenamiento& orig) {
}

DtEntrenamiento::~DtEntrenamiento() {
}

ostream& operator<<(ostream& output, DtEntrenamiento* & clase){
    std::string cadena = "";
 
    std::stringstream out;
    out << clase->getId();
    cadena=out.str();
  
    output <<"\nID Clase: "<<cadena
            <<"\nNombre: "<<clase->getNombre()
            <<"\nTurno: "<<clase->getTurno()
            <<"\nEn Rambla: "<<clase->getEnRambla();
    return output;
}