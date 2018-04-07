/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Spinning.h
 * Author: kapo_
 *
 * Created on 16 de marzo de 2018, 03:12 PM
 */

#ifndef SPINNING_H
#define SPINNING_H
#include "Clase.h"
using namespace std;
class Spinning : public Clase {
    
private:
    int cantBicicletas;
public:
    Spinning(int,string,Turno,int);
    //Spinning(int, string, Turno, int);
    Spinning();
    Spinning(const Spinning& orig);
    virtual ~Spinning();
    /*Getters*/
    int getCantBicicletas();
    
    /*Setters*/
    void setCantBicicletas(int);
    /*Extra functions belonging to this class*/
    
    int cupo();
};

#endif /* SPINNING_H */

