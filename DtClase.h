/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtClase.h
 * Author: mcurbelo
 *
 * Created on March 19, 2018, 3:33 PM
 */

#ifndef DTCLASE_H
#define DTCLASE_H
#include <string>
#include "eTurno.h"
using namespace std;
class DtClase {
public:
    DtClase();
    DtClase(int,string, Turno);
    DtClase(const DtClase& orig);
    virtual ~DtClase();
    
    void setId(int);
    void setNombre(string);
    void SetTurno(Turno);
    
    int getId();
    string getNombre();
    Turno getTurno();
private:
    int id;
    string nombre;
    Turno turno;
};

#endif /* DTCLASE_H */

