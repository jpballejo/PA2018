/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entrenamiento.cpp
 * Author: kapo_
 * 
 * Created on 16 de marzo de 2018, 03:36 PM
 */

#include "Entrenamiento.h"

void Entrenamiento::setEnRambla(bool enRambla) {
    this->enRambla = enRambla;
}

bool Entrenamiento::getEnRambla() {
    return this->enRambla;
}

int Entrenamiento::cupo() {
     if(this->enRambla){
        return 20;
    }else{
        return 10;
    }
}


Entrenamiento::Entrenamiento(int id, string nombre, Turno t, bool rambla) : Clase(id,nombre,t) {
    this->enRambla = rambla;
}


//Entrenamiento::Entrenamiento(const Entrenamiento& orig) {
//}

Entrenamiento::~Entrenamiento() {
}


//Entrenamiento::Entrenamiento(int id, string nombre, Turno t , bool rambla) {
//    this->setId(id);
//    this->setNombre(nombre);
//    this->setTurno(t);
//    this->enRambla = rambla;
//}


