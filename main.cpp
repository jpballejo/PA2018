/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kapo_
 *
 * Created on 16 de marzo de 2018, 02:39 PM
 */

#include <cstdlib>
#include <iostream>
#include <limits>
#include<list>
#include <string>
#include<sstream>
#include <random>
#include "Clase.h"
#include "Spinning.h"
#include "Entrenamiento.h"
#include "Socio.h"
#include "DtSocio.h"
#include "Inscripcion.h"
#include "eTurno.h"
#include "DtClase.h"
#include "DtSpinning.h"
#include "DtEntrenamiento.h"
#include "Fecha.h"
using namespace std;

int const MAX_SOCIOS = 10, MAX_CLASES = 10;
int CantSocios = 0;
int CantClases = 0;
int Cant = 0;

Socio* arreglo_socios[MAX_SOCIOS];
Clase* arreglo_clases[MAX_CLASES];

/*
 * 
 */

// funciones solicitadas 
// Funcion a)
void agregarSocio(string,string);
// Funcion b)
void agregarClase(DtClase&);
// Funcion c)
void agregarInscripcion(string, int, Fecha*);
// Funcion d)
void borrarInscripcion(string, int);
// Funcion e)
DtSocio** obtenerInfoSociosPorClase(int,int&);
// Funcion f)
DtClase& obtenerClase(int);

void infoSocio();
void datosSocio ();
void mostrarClaseS();
void mostrarSocios();
bool existeSocio(string);
void pedirDatosClase();
void agregarClase(DtClase&);
bool existeClase(int);
void inscribirSocio();
void mostrarInscripciones();
void borrarSocio();
Socio* existeSociop(string);
Clase* existeClasep(int);
Fecha* armarFecha();



//Clase* tipoClase(DtClase& clase);

int main(int argc, char** argv) {
    
    for (int i = 0; i < MAX_SOCIOS; i++)
        arreglo_socios[i] = NULL;

    for (int j = 0; j < MAX_CLASES; j++)
        arreglo_clases[j] = NULL;

    int idClase;
   
    string ci;
    int opcionMenu;
    do {
        cout << "\n1- Agregar socio\n2- Agregar clase\n3- Inscribir a clase\n4- Borrar Inscripcion\n5- obtenerInfoSociosPorClase\n6- Obtener Clase\n0- Salir\n";
        cin>>opcionMenu;
        switch (opcionMenu) {
            case 1:
             datosSocio ();
                break;
            case 2:
               pedirDatosClase();
                break;
            case 3:
                inscribirSocio();
                break;
            case 4:
                borrarSocio();
                break;
            case 5:
                infoSocio();
                break;
            case 6:
                mostrarClaseS ();
                break;
            
            case 0:
                break;
            default:
                cout << "\nOpción incorrecta. Por favor intente nuevamente.\n";
                break;
        }
    } while (opcionMenu != 0);


    return 0;
    
}

void infoSocio(){
DtSocio** arreglo_dtSocio;
int idClase=0;

try {
    cout << "ID Clase: ";
    cin>>idClase;
    if(!existeClase(idClase))
        cout<<"No existe la clase ingresada";
    
    arreglo_dtSocio = obtenerInfoSociosPorClase(idClase, CantSocios);
    if (arreglo_dtSocio != NULL){
        cout<< "\nLa clase "<< obtenerClase(idClase).getNombre()<<" tiene Inscriptos  los socios:";
        cout<< "\nNombre\t\tCedula \n";
        for (int i = 0; i < CantSocios; i++) {
            if (arreglo_dtSocio[i] != NULL) {
                cout << arreglo_dtSocio[i]->getNombre() + "\t\t"+arreglo_dtSocio[i]->getCi() + "\n";
            }
        }
    }else{
            cout<< "\nLa clase "<< obtenerClase(idClase).getNombre()<<" NO tiene socios Inscriptos\n\n";
       }
    }
catch (std::invalid_argument& ia) {
    cout<<ia.what();
}
}

DtSocio** obtenerInfoSociosPorClase(int idClase, int& cantSocios) {
     DtSocio ** arreglo_socio = NULL;
     int cantInscriptos;
        
    for(int i=0; i< cantSocios; i++){
        if (arreglo_clases[i]!=NULL){
            
            if(arreglo_clases[i]->getId() == idClase){
//                cantInscriptos = arreglo_clases[i]->inscripcionesSize();
                //for(int j=0; j< cantInscriptos ; j++){
                    arreglo_socio = arreglo_clases[i]->getInscriptos(cantInscriptos);
                
                break;
            }
        }
    }
    return arreglo_socio;
}  
 
void mostrarClaseS (){
   DtClase* clase;
   int idClase=0;
   try{
       
       cout << "Ingrese el ID de Clase: ";
        cin>>idClase;
        
        clase = &obtenerClase(idClase);
        if (clase != NULL){

        if (DtSpinning* cla = dynamic_cast <DtSpinning *>(clase))
            cout<<cla;
        if (DtEntrenamiento* cla = dynamic_cast <DtEntrenamiento *>(clase))
                cout<<cla;
        }
        else{
            cout<<" No hay ingresadas Clases";
        }
   }catch (std::invalid_argument& ia){
       cout << ia.what();}
                
}

DtClase& obtenerClase(int idClase) {

        if(existeClase(idClase)!=true)
            throw std::invalid_argument("No existe la clase");
    Clase* clase = NULL;
    DtClase* resultado = NULL;


    for (int i = 0; i < CantClases; i++) {
        if (arreglo_clases[i] != NULL && arreglo_clases[i]->getId() == idClase) {
            if (Entrenamiento* entrenamiento = dynamic_cast<Entrenamiento*> (arreglo_clases[i])){
                resultado = new DtEntrenamiento(entrenamiento->getId(), entrenamiento->getNombre(), entrenamiento->getTurno(), entrenamiento->getEnRambla());
                break;
            }
            
            if (Spinning* spinning = dynamic_cast<Spinning*> (arreglo_clases[i])){
                resultado = new DtSpinning(spinning->getId(), spinning->getNombre(), spinning->getTurno(), spinning->getCantBicicletas());
                break;
            }
            throw invalid_argument("La clase no existe");
        }
    }
    return * resultado;
}

Fecha* armarFecha() {
    int aa, mm, dd;
    Fecha * fech;
   try {
    cout << "\nIngrese la fecha: \n";
    cout<<"Ingrese año: ";
    cin>>aa;
    cout<<"Ingrese mes: ";
    cin>>mm;
    cout<<"Infrese día: ";
    cin>>dd;
    
    fech = new Fecha(dd, mm, aa);
        
    }
    catch (std::invalid_argument& e){
        cout<<e.what();
    }
    return fech ;
}
//Fecha* armarFecha() {
//    int dia = 0;
//    int mes = 0;
//    int anio = 0;
//    cout << "Ingrese la fecha: \n";
//    cout << "Ingrese dia: \n";
//    cin>>dia;
//    if (dia < 1 && dia > 31){
//        throw invalid_argument("El dia no es correcto");}
//    cout << "Ingrese el mes: \n";
//    cin>>mes;
//    if(mes<1 && mes >12){
//        throw invalid_argument("El mes no es correcto");}
//    cout << "Ingrese el año: \n";
//    cin>>anio;
//    if (anio<1900 && anio>2018){
//        throw invalid_argument("Ell año no es correcto");}
//    Fecha * fech = new Fecha(dia, mes, anio);
//
//    return fech;
//
//}

bool existeClase(int id) {

    for (int a = 0; a < CantClases; a++) {
        if (arreglo_clases[a]!=NULL && arreglo_clases[a]->getId() == id)
            return true;
    }
    return false;
}

void inscribirSocio() {
    int codClase=0;
    string ciS;
    try{
        cout << "Incribir Socio a clase\n";
        cout << "Ingrese la cedula:\n";
        cin>>ciS;
        cout << "Ingrese el codigo de la clase:\n";
        cin>>codClase;
//        if (existeSocio(ciS) == false && existeClase(codClase) == false)          
//            cout <<"El socio o la clase no existen";
        
        agregarInscripcion(ciS, codClase, armarFecha());
        cout <<"\n\nSocio Dado de Alta\n";
        
    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }
}

void agregarInscripcion(string ci, int codC, Fecha* fecha) {
Socio* soc = existeSociop(ci);
Clase* clas = existeClasep(codC);
    if (clas == NULL)
        throw std::invalid_argument("No existe la clase");
    if (soc == NULL)
        throw std::invalid_argument("No existe el socio");
    if (!clas->socioEnClase(ci)) {
        Inscripcion * ins = new Inscripcion(soc, fecha);
        clas->setInscripcion(ins);
    } else {
        throw std::invalid_argument("El socio ya esta inscripto a la clase.");
    }
}

void mostrarInscripciones() {

    int idClase;

    cout << "ID Clase: ";
    cin>>idClase;

    Clase* clase = NULL;

    for (int i = 0; i < CantClases; i++)
        if (arreglo_clases[i] != NULL && arreglo_clases[i]->getId() == idClase) {
            clase = arreglo_clases[i];
            break;
        }

    if (clase == NULL) {
        throw invalid_argument("la clase no existe");
    }

    Inscripcion** inscripciones = clase->getInscripcion();

    Entrenamiento* entrenamiento = dynamic_cast<Entrenamiento*> (clase);

    int cupos = 0;

    if (entrenamiento != NULL) {
        cupos = entrenamiento->cupo();
    } else {
        Spinning* spinning = dynamic_cast<Spinning*> (clase);

        cupos = spinning->cupo();
    }

    for (int i = 0; i < cupos; i++) {
        if (inscripciones[i] != NULL) {
            cout << "SOCIO: " + inscripciones[i]->getSocio()->getNombre() + "\n";
        }
    }

}

void borrarSocio(){
    string ci="";
    int idClase;
               
try {
    cout << "\n Borrar Inscripción de un Socio \nCI Socio: ";
        cin>>ci;
        cout << "\nID Clase:";
        cin >> idClase;
        if ((existeClase(idClase))!=false && (existeSocio(ci)!=false)){
            borrarInscripcion(ci, idClase);
            cout<<"Socio Borrado de La Clase ";
        }
        else throw std::invalid_argument("El socio o la clase no existen"); 
   } catch (std::invalid_argument& ia) {
       cout << ia.what();
   }
}
void borrarInscripcion(string ciSocio, int idClase) {

    for (int i = 0; i < CantClases; i++)
        if (arreglo_clases[i] != NULL && arreglo_clases[i]->getId() == idClase) {
            arreglo_clases[i]->borroInscricion(ciSocio);
            break;
        }
}
    
void pedirDatosClase() {
    int id=0, optT=0, op=0,cantBici=0;;
    string nombre=" ";  
    Turno t;
try{    
    
        cout << "\nIngrese ID de la clase\n";
        cin>>id;
        cout << "\nIngrese nombre de la clase\n";
        cin>>nombre;        
        cout << "\nIngrese turno de la clase:\n1- Manana\n2- Tarde\n3- Noche\n";
        cin>>optT;
        switch (optT) {
            case 1:
                t = Turno::Manana;
                break;
            case 2:
                t = Turno::Tarde;
                break;
            case 3:
                t = Turno::Noche;
                break;
            default:
                break;
        }
        cout << "\nQue tipo de clase desea crear?\n1- Spinning\n2- Entrenamiento\n";
        cin>>op;
    if(op==1){
        cout<<"Ingrese la cantidad de bicicletas: "<<endl;
        cin>>cantBici;
        if (existeClase(id))
            throw std::invalid_argument("El ID de la clase ya existe");
        
        DtSpinning * DtSpin = new DtSpinning(id,nombre,t,cantBici);
        agregarClase(*DtSpin);//y esto es necesario porque no es por referencia es por el coso 
    }
    if(op==2){cout << "El entrenamiento es en rambla?\n1- Si\n2- No\n";
    cin>>op;
    if(op==1){
        if (existeClase(id))
            throw std::invalid_argument("El ID de la clase ya existe");
        
        DtEntrenamiento * DtEntre = new DtEntrenamiento(id,nombre,t,true);
        agregarClase(*DtEntre);
    }
    if(op==2){
        DtEntrenamiento * DtEntre = new DtEntrenamiento(id,nombre,t,false);
        agregarClase(*DtEntre);
    }
           
    }
    cout<<"\nClase ingresada con éxito\nPulse Intro para continuar...\n ";
    cin>>op;
              
    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }
}

void agregarClase(DtClase& clase) {
    Clase * claseDef;
    
        if (DtSpinning * DtSpin = dynamic_cast<DtSpinning*>(&clase))
            claseDef = new Spinning(DtSpin->getId(),DtSpin->getNombre(),DtSpin->getTurno(),DtSpin->getCantBicicletas());
        if (DtEntrenamiento * DtEntre = dynamic_cast<DtEntrenamiento*>(&clase))
            claseDef = new Entrenamiento(DtEntre->getId(),DtEntre->getNombre(),DtEntre->getTurno(),DtEntre->getEnRambla());
            
        if(CantClases>= MAX_CLASES)
                throw std::invalid_argument("Se llegó al Tope de Clases");
            else{
                arreglo_clases[CantClases]=claseDef;
                CantClases++;
            }   
        }
       

void datosSocio (){
 string ci, nombre;
 try {
        cout << "\nIngreso de Nuevo Socio: \nNúmero de Cédula del Socio:\n";
        cin>>ci;
        if (existeSocio(ci) == true) {
            throw std::invalid_argument("\nYa existe un Socio con esta cédula\n");
        } else {
            cout << "\nNombre del Socio:\n";
            cin>>nombre;                       
        }
     agregarSocio(ci,nombre);         
 } catch (std::invalid_argument& ia) {
        cout << ia.what() << endl;
    }
}

void agregarSocio(string ci, string nombre) {
Socio* s = new Socio(ci, nombre);
    
    if (CantSocios >= MAX_SOCIOS)
        throw std::invalid_argument("Supera Tope de socios");
    else{
        arreglo_socios[CantSocios]=s;
        CantSocios++;}

}



Clase* existeClasep(int cod) {
    Clase* clase = NULL;
    for (int i = 0; i < CantClases; i++) {
        if (arreglo_clases != NULL && arreglo_clases[i]->getId() == cod) {

            clase = dynamic_cast<Entrenamiento*> (arreglo_clases[i]);
            if (clase != NULL) {
                return clase;
            } else {
                clase = dynamic_cast<Spinning*> (arreglo_clases[i]);
                return clase;
            }
            
        }
    }
    return clase;
 }
Socio* existeSociop(string cedula) {
    for (int i = 0; i < CantSocios; i++) {
        if (arreglo_socios[i] != NULL && arreglo_socios[i]->getCI().compare(cedula) == 0)
            return arreglo_socios[i];
    }
    return NULL;

}
bool existeSocio(string CI) {

    for (int i = 0; i < CantSocios; i++) {
        if (arreglo_socios != NULL && arreglo_socios[i]->getCI().compare(CI) == 0) {
            return true;
        }
    }
    return false;
}



