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
//void DtEntrenamiento::setEnRambla(bool enRambla){
//    this->enRambla = enRambla;
//}

int DtEntrenamiento::getId(){
    return DtClase::getId();
}

string DtEntrenamiento::getNombre(){
    return DtClase::getNombre();
}
string DtEntrenamiento::getTurnoS(){
    return DtClase::getTurnoS();
}

Turno DtEntrenamiento::getTurno(){
    return DtClase::getTurno();
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

ostream& operator<<(ostream& os, DtEntrenamiento*& entrena){
    string r;
    if(entrena->getEnRambla()){
        r="Si";
    }else {
        r="No";
    }
    os <<"\nID Empresa: "<<entrena->getId()
            <<"\nNombre: "<<entrena->getNombre()
            <<"\nTurno: "<<entrena->getTurnoS()
            <<"\nEn Rambla: " << r << endl;
    
    return os;
}