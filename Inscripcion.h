/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Incripcion.h
 * Author: kapo_
 *
 * Created on 16 de marzo de 2018, 04:33 PM
 */

#ifndef INCRIPCION_H
#define INCRIPCION_H
#include "Socio.h"
#include "Fecha.h"
//#include "DtSocio.h"
using namespace std;
class Inscripcion {
public:
//    DtSocio** infoSocio(Clase&,int);
    Inscripcion();
    Inscripcion(const Inscripcion& orig);
    ~Inscripcion();
    Inscripcion(Socio*,Fecha*);
//    Eliminar(const Inscripcion&);
    /*Getters*/
    Socio* getSocio();
    Fecha* getFecha();
    /*Setters*/
    
    void setSocio(Socio*);
    void setFecha(Fecha*);
private:
    Socio* socio;
    Fecha* fecha;
};

#endif /* INCRIPCION_H */

