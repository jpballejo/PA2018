/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtClase.cpp
 * Author: mcurbelo
 * 
 * Created on March 19, 2018, 3:33 PM
 */
#include<iostream>
#include "DtClase.h"
#include "DtSpinning.h"
#include "DtEntrenamiento.h"
using namespace std;

void DtClase::setId(int id){
    this->id = id;
}

void DtClase::setNombre(string nombre){
    this->nombre = nombre;
}

void DtClase::SetTurno(Turno turno){
    this->turno = turno;
}

int DtClase::getId(){
    return this->id;
}

string DtClase::getNombre(){
    return this->nombre;
}

Turno DtClase::getTurno(){
    return this->turno;
}


DtClase::DtClase(int id, string nombre, Turno turno){
    this->id = id;
    this->nombre = nombre;
    this->turno = turno;
}
DtClase::DtClase() {
}

DtClase::DtClase(const DtClase& orig) {
}

DtClase::~DtClase() {
}

ostream& operator<<(ostream& os, const DtClase& clase){
    string turno="";
    
    if (clase.turno == Turno::Manana){
        turno = "Mañana";
    }else if (clase.turno == Turno::Tarde){
        turno = "Tarde";
    }
    else{
        turno = "Noche";
    }
    
    os << "Id Clase: "<<clase.id<<endl;
    os << "Nombre: "<< clase.nombre<<endl;
    os <<"Turno: "<< turno<<endl;
    
    
    const DtSpinning* dtSpin = dynamic_cast<const DtSpinning*> (&clase);
    
    if(dtSpin) {
        os << *dtSpin;
    } 
        const DtEntrenamiento* dtEntr = dynamic_cast<const DtEntrenamiento*> (&clase);
        if(dtEntr){
        os << *dtEntr;}
    
    return os;
}
