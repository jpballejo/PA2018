/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Incripcion.cpp
 * Author: kapo_
 * 
 * Created on 16 de marzo de 2018, 04:33 PM
 */

#include "Inscripcion.h"
#include "DtSocio.h"
#include "Clase.h"
DtSocio** Inscripcion::infoSocio(Clase * cla,int cantI){
    Inscripcion**ins=new Inscripcion*[cantI](); 
    for (int i =0;i>=MAX_Inscripcion;i++){
        if(ins[i]->socio->getCI().compare(cla->getSocio()))    
        ins[i]->socio->getNombre();}
    //DtSocio ** soc = new DtSocio()
}
Socio* Inscripcion::getSocio(){
    return this->socio;
}

Fecha* Inscripcion::getFecha(){
    return this->fecha;
}

void Inscripcion::setSocio(Socio* socio){
    this->socio = socio;
}

void Inscripcion::setFecha(Fecha* fecha){
    this->fecha = fecha;
}

Inscripcion::Inscripcion() {
}

Inscripcion::Inscripcion(const Inscripcion& orig) {
}


Inscripcion::~Inscripcion() {
   // delete this->socio;
    delete this->fecha;
}

Inscripcion::Inscripcion(Socio* socio, Fecha* fech) {
    this->socio=socio;
    this->fecha= fech;
}
