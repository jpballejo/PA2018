/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Socio.cpp
 * Author: kapo_
 * 
 * Created on 16 de marzo de 2018, 04:33 PM
 */

#include "Socio.h"

void Socio::setCI(string CI){
    this->CI = CI;
}

void Socio::setNombre(string nombre){
    this->nombre = nombre;
}

string Socio::getCI(){
    return this->CI;
}

string Socio::getNombre(){
    return this->nombre;
}

Socio::Socio(string ci, string nombre){
    this->CI = ci;
    this->nombre = nombre;
}
Socio::Socio() {
}

Socio::Socio(const Socio& orig) {
}

Socio::~Socio() {
}

