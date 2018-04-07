/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Spinning.cpp
 * Author: kapo_
 * 
 * Created on 16 de marzo de 2018, 03:12 PM
 */

#include "Spinning.h"

int Spinning::cupo() {
    return this->cantBicicletas;
}

Spinning::Spinning(int id,string nombre, Turno t,int cantBicicletas) : Clase(id,nombre,t) {
    this->cantBicicletas = cantBicicletas;
}

//Spinning::Spinning(int id, string nombre, Turno t, int cantBicicletas) {
//    this->setId(id);
//    this->setNombre(nombre);
//    this->setTurno(t);
//    this->cantBicicletas = cantBicicletas;
//}

int Spinning::getCantBicicletas() {
    return this->cantBicicletas;
}

void Spinning::setCantBicicletas(int cantBicicletas) {
    this->cantBicicletas = cantBicicletas;
}

Spinning::Spinning() {
}

Spinning::Spinning(const Spinning& orig) {
}

Spinning::~Spinning() {
}

