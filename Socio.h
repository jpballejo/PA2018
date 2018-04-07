/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Socio.h
 * Author: kapo_
 *
 * Created on 16 de marzo de 2018, 04:33 PM
 */

#ifndef SOCIO_H
#define SOCIO_H
#include<string>
using namespace std;
class Socio {
private:
    string CI;
    string nombre;
public:
    Socio(string,string);
    Socio();
    Socio(const Socio& orig);
    virtual ~Socio();
    /*Getters*/
    string getNombre();
    string getCI();
    /*Setters*/
    void setNombre(string);
    void setCI(string);
    //Clase * claseEnSocio(int idClase);
};

#endif /* SOCIO_H */

