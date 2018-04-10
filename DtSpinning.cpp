/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtSpinning.cpp
 * Author: mcurbelo
 * 
 * Created on March 19, 2018, 3:35 PM
 */

#include "DtSpinning.h"
#include<sstream>

//void DtSpinning::setCantBicicletas(int cantBicicletas){
//    this->cantBicicletas = cantBicicletas;
//}
int DtSpinning::getId(){
    return DtClase::getId();
}

string DtSpinning::getNombre(){
    return DtClase::getNombre();
}

Turno DtSpinning::getTurno(){
    return DtClase::getTurno();
}

int DtSpinning::getCantBicicletas(){
    return this->cantBicicletas;
}

DtSpinning::DtSpinning() {
}

DtSpinning::DtSpinning(int id, string nombre, Turno turno, int cantBicicletas):
    DtClase(id,nombre,turno){
    this->cantBicicletas = cantBicicletas;
}
DtSpinning::DtSpinning(const DtSpinning& orig) {
}

DtSpinning::~DtSpinning() {
}

ostream& operator<<(ostream& os,  DtSpinning& spin){
   
    os <<"\nID Empresa: "<<spin.getId()
            <<"\nNombre: "<<spin.getNombre()
            <<"\nTurno: "<<spin.getTurno()
            << "Cantidad de bicicletas: " << spin.getCantBicicletas();
    
    return os;
}
