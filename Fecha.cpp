/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fecha.cpp
 * Author: mcurbelo
 * 
 * Created on March 19, 2018, 3:33 PM
 */

#include "Fecha.h"

int Fecha::getDia(){
    return this->dia;
}

int Fecha::getMes(){
    return this->mes;
}

int Fecha::getAnio(){
    return this->anio;
}

void Fecha::setDia(int dia){
    this->dia = dia;
}
Fecha::Fecha(int dia, int mes, int anio) {
    this->dia =dia;
    this->mes =mes;
    this->anio =anio;
}

void Fecha::setMes(int mes){
    this->mes = mes;
}

void Fecha::setAnio(int anio){
    this->anio = anio;
}

Fecha::Fecha(const Fecha& orig) {
}

Fecha::~Fecha() {
}

