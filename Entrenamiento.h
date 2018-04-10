/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entrenamiento.h
 * Author: kapo_
 *
 * Created on 16 de marzo de 2018, 03:36 PM
 */

#ifndef ENTRENAMIENTO_H
#define ENTRENAMIENTO_H
#include <iostream>
#include "Clase.h"
#include "eTurno.h"
using namespace std;
class Entrenamiento : public Clase {
private:
    bool enRambla;
public:
    
    Entrenamiento(int,string,Turno,bool);
    Entrenamiento();
    Entrenamiento(const Entrenamiento& orig);
    virtual ~Entrenamiento();
    /*Getters*/
    
    bool getEnRambla();
    /*Setters*/
    
    //void setEnRambla(bool);
    /*Extra functions belonging to this class*/
    
    int cupo();

};

#endif /* ENTRENAMIENTO_H */

