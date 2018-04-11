/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtEntrenamiento.h
 * Author: mcurbelo
 *
 * Created on March 19, 2018, 3:34 PM
 */

#ifndef DTENTRENAMIENTO_H
#define DTENTRENAMIENTO_H
#include "DtClase.h"
class DtEntrenamiento : public DtClase{
public:
    DtEntrenamiento(int, string, Turno, bool);
    DtEntrenamiento();
    DtEntrenamiento(const DtEntrenamiento& orig);
    virtual ~DtEntrenamiento();
    
    int getId();
    string getNombre();
    Turno getTurno();
    string getTurnoS();    
    bool getEnRambla();
    
    friend ostream& operator<<(ostream&, DtEntrenamiento* &);

private:
    bool enRambla;
};

#endif /* DTENTRENAMIENTO_H */

