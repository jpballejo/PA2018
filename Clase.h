/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clase.h
 * Author: kapo_
 *
 * Created on 16 de marzo de 2018, 02:53 PM
 */

#ifndef CLASE_H
#define CLASE_H
#include<string>
#include "eTurno.h"
#include "Inscripcion.h"
#include "DtSocio.h"

#define MAX_Inscripcion 50


using namespace std;

class Clase {
private:
    Inscripcion* inscripciones[MAX_Inscripcion];
    int id;
    string nombre;
    Turno turno;


public:
    Clase(int, string, Turno);
    Clase();
    Clase(const Clase& orig);
    virtual ~Clase();

    /*Setters*/
    void setId(int);
    void setNombre(string);
    void setTurno(Turno);
    /*Getters*/
    int getId();
    string getNombre();
    Turno getTurno();
    Inscripcion** getInscripcion();
    DtSocio ** getInscriptos(int );
    bool socioEnClase(string ci);
    void setInscripcion(Inscripcion * inscripcion);
    /*Extra functions belonging to this class*/
    virtual int cupo() = 0;
    int inscripcionesSize();
    void borroInscricion(string);

};

#endif /* CLASE_H */

