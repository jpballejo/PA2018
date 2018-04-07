/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtSocio.cpp
 * Author: mcurbelo
 * 
 * Created on March 19, 2018, 3:15 PM
 */

#include "DtSocio.h"


void DtSocio::setCi(int CI){
    this->CI = CI;
}

void DtSocio::setNombre(string nombre){
    this->nombre = nombre;
}

string DtSocio::getCi(){
    return this->CI;
}

string DtSocio::getNombre(){
    return this->nombre;
}
DtSocio::DtSocio() {
}

DtSocio::DtSocio(string ci, string nombre){
    this->CI = ci;
    this->nombre = nombre;
}
DtSocio::DtSocio(const DtSocio& orig) {
}

DtSocio::~DtSocio() {
}

