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
DtEntrenamiento::DtEntrenamiento(int id, string nombre, Turno turno, bool enRambla):DtClase(id, nombre, turno){
     this->enRambla = enRambla;
}
DtEntrenamiento::DtEntrenamiento(const DtEntrenamiento& orig) {
}

DtEntrenamiento::~DtEntrenamiento() {
}

ostream& operator<<(ostream& os, const DtEntrenamiento& entrena){
    string r;
    if(entrena.enRambla){
        r="Si";
    }else {
        r="No";
    }
    
    os <<"En Rambla: " << r << endl;
    
    return os;
}