/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fecha.h
 * Author: mcurbelo
 *
 * Created on March 19, 2018, 3:33 PM
 */

#ifndef FECHA_H
#define FECHA_H

class Fecha {
public:
    Fecha (int,int,int);
    Fecha(const Fecha& orig);
    ~Fecha();
  //  Fecha(int,int,int);
    int getDia();
    int getMes();
    int getAnio();
    
    void setDia(int);
    void setMes(int);
    void setAnio(int);
    
private:
    int dia;
    int mes;
    int anio;
};

#endif /* FECHA_H */

