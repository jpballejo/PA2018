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

void DtSpinning::setCantBicicletas(int cantBicicletas){
    this->cantBicicletas = cantBicicletas;
}

int DtSpinning::getCantBicicletas(){
    return this->cantBicicletas;
}

DtSpinning::DtSpinning() {
}

DtSpinning::DtSpinning(int id, string nombre, Turno turno, int cantBicicletas){
    DtClase(id,nombre,turno);
    this->cantBicicletas = cantBicicletas;
}
DtSpinning::DtSpinning(const DtSpinning& orig) {
}

DtSpinning::~DtSpinning() {
}

ostream& operator<<(ostream& output, DtSpinning* & clase){
 std::string cadena = "";
 
    std::stringstream out;
    out << clase->getId();
    cadena=out.str();
    output <<"\nID Clase: "<<cadena
            <<"\nNombre: "<<clase->getNombre()
            <<"\nTurno: "<<clase->getTurno()
            <<"\nCantidad Bicicletas: "<<clase->getCantBicicletas();
    return output;
}
