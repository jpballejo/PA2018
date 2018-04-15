/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clase.cpp
 * Author: kapo_
 * 
 * Created on 16 de marzo de 2018, 02:53 PM
 */

#include "Clase.h"
#include<string.h>
#include <stdexcept>
#include <iostream>
/*Getters*/
using namespace std;

int Clase::inscripcionesSize(){
    int i = 0;
    for(i; i<MAX_Inscripcion;i++){
        if(this->inscripciones[i] == NULL)
            break;}
    return i;
}
Inscripcion* Clase::getPunteroInscripcion(int p){
this->inscripciones[p];}
Inscripcion** Clase::getInscripcion() {
    return this->inscripciones;
}

Turno Clase::getTurno() {
    return this->turno;
}

int Clase::getId() {
    return this->id;
}

string Clase::getNombre() {
    return this->nombre;
}

/*Setters*/


bool Clase::socioEnClase(string ci) {
   // Socio* np = NULL;
    for (int i = 0; i < MAX_Inscripcion; i++) {
     
        if (this->inscripciones[i] != NULL&&inscripciones[i]->getSocio()->getCI().compare(ci)==0) {
            return true;
          
        }
        
    }
    return false;
    
}

void Clase::setInscripcion(Inscripcion *inscripcion) {
    
        if(this->cupo() > this->inscripcionesSize()){
            int i = 0;
            for (i; i < MAX_Inscripcion; i++) {
                if (this->inscripciones[i] == NULL) {
                    this->inscripciones[i] = inscripcion;
                    break;
                }
            }
            if (i == 50)
                return throw std::invalid_argument("Maximo de inscripciones alcanzado");
        }
        else{
            return throw std::invalid_argument("El cupo ha sido alcanzado");
        }
    
    
    

    

}

void Clase::setTurno(Turno turno) {
    this->turno = turno;
}

void Clase::setId(int id) {
    this->id = id;
}

void Clase::setNombre(string nombre) {
    this->nombre = nombre;
}

/*Creators and destroyers*/
Clase::Clase() {
    for (int i = 0; i < MAX_Inscripcion; i++)
        this->inscripciones[i] = NULL;
}
//Socio * Socio::socioEnClase(string ci);

Clase::Clase(int id, string nombre, Turno t) {
    this->id = id;
    this->nombre = nombre;
    this->turno = t;

    for (int i = 0; i < MAX_Inscripcion; i++)
        this->inscripciones[i] = NULL;
}

Clase::Clase(const Clase& orig) {
    this->id = orig.id;
    this->nombre = orig.nombre;
}
//Clase::Delins(Inscripcion ins){
  //  delete ins;
    
    
    

Clase::~Clase() {
    
}

