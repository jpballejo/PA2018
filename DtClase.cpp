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

#include "DtClase.h"

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


