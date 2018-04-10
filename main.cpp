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

Socio* arreglo_socios[MAX_SOCIOS];
Clase* arreglo_clases[MAX_CLASES];

/*
 * 
 */
void infoSocio();
void datosSocio ();
void mostrarClaseS();
void mostrarSocios();
void agregarSocio(string,string);
bool existeSocio(string);
void agregarInscripcion(string, int, Fecha*);
void pedirDatosClase();
void agregarClase(DtClase&);
bool existeClase(int);
void inscribirSocio();
void mostrarInscripciones();
void borrarSocio();
Socio* existeSociop(string);
Clase* existeClasep(int);
void borrarInscripcion(string, int);
DtSocio** obtenerInfoSociosPorClase(int,int&);
DtClase& obtenerClase(int);
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
            throw std::invalid_argument("No existe la clase ingresada");
                arreglo_dtSocio = obtenerInfoSociosPorClase(idClase, CantSocios);
                for (int i = 0; i < CantSocios; i++) {
                    if (arreglo_dtSocio[i] != NULL) {
                        cout << "Nombre: " + arreglo_dtSocio[i]->getNombre() + "\n";
                        cout << "Cedula: " + arreglo_dtSocio[i]->getCi() + "\n";
                    }
                }
}catch (std::invalid_argument& ia) {cout<<ia.what();}


}
void borrarSocio(){
    string ci="";
    int idClase;
               
         try {
                
                cout << "CI Socio: ";
                cin>>ci;
                cout << "ID Clase:";
                cin >> idClase;
                    if ((existeClase(idClase))!=false && (existeSocio(ci)!=false)){
                        borrarInscripcion(ci, idClase);}
                    else throw std::invalid_argument("El socio o la clase no existen"); 
            } catch (std::invalid_argument& ia) {
                cout << ia.what();
            }}

void mostrarClaseS (){
   DtClase* clase;
   int idClase=0;
   try { 
        cout << "ID Clase: ";
        cin>>idClase;

        if(existeClase(idClase)!=true)
            throw std::invalid_argument("No existe la clase");

        clase = &obtenerClase(idClase);
                cout<<clase;
   }catch (std::invalid_argument& ia){cout << ia.what();}
                
}
DtClase& obtenerClase(int idClase) {

    Clase* clase = NULL;
    DtClase* resultado = NULL;


    for (int i = 0; i < CantClases; i++) {
        if (arreglo_clases[i] != NULL && arreglo_clases[i]->getId() == idClase) {

            clase = arreglo_clases[i];

            Entrenamiento* entrenamiento = dynamic_cast<Entrenamiento*> (clase);

            if (entrenamiento != NULL) {
                resultado = new DtEntrenamiento(entrenamiento->getId(), entrenamiento->getNombre(), entrenamiento->getTurno(), entrenamiento->getEnRambla());
                return* resultado;

            } else {

                Spinning* spinning = dynamic_cast<Spinning*> (clase);

                if (spinning != NULL) {
                    resultado = new DtSpinning(spinning->getId(), spinning->getNombre(), spinning->getTurno(), spinning->getCantBicicletas());
                    return* resultado;
                }

            }

            throw invalid_argument("La clase no existe");

        }

    }
}
Fecha* armarFecha() {
    int dia = 0;
    int mes = 0;
    int anio = 0;
    cout << "Ingrese la fecha: \n";
    cout << "Ingrese dia: \n";
    cin>>dia;
    if (dia < 1 && dia > 31){
        throw invalid_argument("El dia no es correcto");}
    cout << "Ingrese el mes: \n";
    cin>>mes;
    if(mes<1 && mes >12)
        throw invalid_argument("El mes no es correcto");
    cout << "Ingrese el año: \n";
    cin>>anio;
    if (anio<1900 && anio>2018)
        throw invalid_argument("Año incorrecto");
    Fecha * fech = new Fecha(dia, mes, anio);

    return fech;

}

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

    try {
        cout << "Incribir Socio a clase:\n";
        cout << "Ingrese la cedula:\n";
        cin>>ciS;
        cout << "Ingrese el codigo de la clase:\n";
        cin>>codClase;
        if (existeSocio(ciS) != false && existeClase(codClase) != false) {
            
            agregarInscripcion(ciS, codClase, armarFecha());
        } else {
            throw std::invalid_argument("El socio o la clase no existen");
        }

    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }
}

void agregarInscripcion(string ci, int codC, Fecha* fecha) {
    try {
      
        Socio* soc = existeSociop(ci);
        Clase* clas = existeClasep(codC);
        if (!clas->socioEnClase(ci)) {
            Inscripcion * ins = new Inscripcion(soc, fecha);
            clas->setInscripcion(ins);
        } else {
            throw std::invalid_argument("El socio ya esta inscripto a la clase.");
        }
    } catch (std::invalid_argument & ia) {
        cout << ia.what() << endl;
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

void borrarInscripcion(string ciSocio, int idClase) {

    Socio* socio = NULL;


    for (int i = 0; i < CantSocios; i++)
        if (arreglo_socios[i] != NULL && arreglo_socios[i]->getCI().compare(ciSocio) == 0) {
            socio = arreglo_socios[i];
            break;
        }

    if (socio == NULL) {
        throw invalid_argument("El socio no existe");
    }

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
        if (inscripciones[i] != NULL && inscripciones[i]->getSocio()->getCI().compare(ciSocio) == 0) {
            delete inscripciones[i];
            inscripciones[i] = NULL;
            return;
        }
    }

    throw invalid_argument("La inscripcion no existe");
}

void pedirDatosClase() {
    int id, optT;
    string nombre;  
    Turno t;

    try {
        cout << "\nIngrese ID de la clase\n";
        cin>>id;
        if (existeClase(id))
            throw std::invalid_argument("El ID de la clase ya existe");
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
         DtClase* clase = new DtClase(id,nombre,t);
        agregarClase(*clase);        
    } catch (std::invalid_argument &ia) {
        cout << ia.what() << endl;
    }
}

void agregarClase(DtClase& clase) {
    int optT, cantBicicletas;
    bool enRambla;
    Clase * claseMad;
     
cout << "\nQue tipo de clase desea crear?\n1- Spinning\n2- Entrenamiento\n";
cin>>optT;
    if (optT == 1) {
        cout << "\nIngrese la cantidad de bicicletas\n";
        cin>>cantBicicletas;
        claseMad = new Spinning(clase.getId(), clase.getNombre(), clase.getTurno(), cantBicicletas);
        //return claseSpinning;
    } else if (optT == 2) {
        cout << "El entrenamiento es en rambla?\n1- Si\n2- No\n";
        cin>>optT;
        if (optT == 1) {
            claseMad = new Entrenamiento(clase.getId(), clase.getNombre(), clase.getTurno(), true);
            //return claseEntrenamiento;
        } else {
            claseMad = new Entrenamiento(clase.getId(), clase.getNombre(), clase.getTurno(), false);
         //return claseEntrenamiento;
        }
    } else {
        cout << "\nOpción incorrecta\n";
    }
if (CantClases >= MAX_CLASES)
         throw std::invalid_argument("Tope de Clases");
    else{
        arreglo_clases[CantClases] = claseMad;
        CantClases++;   
    }       
}

//Clase* tipoClase(DtClase& clase){
//   int optT, cantBicicletas;
//    do {
//        cout << "\nQue tipo de clase desea crear?\n1- Spinning\n2- Entrenamiento\n";
//        cin>>optT;
//        if (optT == 1) {
//            cout << "\nIngrese la cantidad de bicicletas\n";
//            cin>>cantBicicletas;
//            Spinning* claseSpinning = new Spinning(clase.getId(), clase.getNombre(), clase.getTurno(), cantBicicletas);
//            return claseSpinning;
//        } else if (optT == 2) {
//            cout << "El entrenamiento es en rambla?\n1- Si\n2- No\n";
//            cin>>optT;
//            if (optT == 1) {
//                Entrenamiento* claseEntrenamiento = new Entrenamiento(clase.getId(), clase.getNombre(), clase.getTurno(), true);
//                return claseEntrenamiento;
//            } else {
//                Entrenamiento* claseEntrenamiento = new Entrenamiento(clase.getId(), clase.getNombre(), clase.getTurno(), false);
//             return claseEntrenamiento;
//            }
//        } else {
//            cout << "\nOpción incorrecta\n";
//        }
//    } while (optT != 1 && optT != 2);
//
//
//
//
//}
void datosSocio (){
 string ci, nombre;
 try {
        cout << "\nIngrese el número de Cédula del nuevo socio\n";
        cin>>ci;
        if (existeSocio(ci) == true) {
            throw std::invalid_argument("\nYa existe un usuario con esta cédula\n");
        } else {
            cout << "\nIngrese el nombre del nuevo socio\n";
            cin>>nombre;                       
        }
     agregarSocio(ci,nombre);   
        
 } catch (std::invalid_argument& ia) {
        cout << ia.what() << endl;
    }




}

void agregarSocio(string ci, string nombre) {
    try {
       
            Socio* s = new Socio(ci, nombre);
            arreglo_socios[CantSocios]=s;
            CantSocios++;
    }
     catch (std::invalid_argument& ia) {
        cout << ia.what() << endl;
    }
}

Socio* existeSociop(string cedula) {
    for (int i = 0; i < CantSocios; i++) {
        if (arreglo_socios[i] != NULL && arreglo_socios[i]->getCI().compare(cedula) == 0)
            return arreglo_socios[i];
    }
    return NULL;

}

Clase* existeClasep(int cod) {
    Clase* clase = NULL;
    for (int i = 0; i < CantClases; i++) {
        if (arreglo_clases[i] != NULL && arreglo_clases[i]->getId() == cod) {

            clase = dynamic_cast<Entrenamiento*> (arreglo_clases[i]);
            if (clase != NULL) {
                return clase;
            } else {
                clase = dynamic_cast<Spinning*> (arreglo_clases[i]);
                return clase;
            }
            //return arreglo_clases[i];
        }
    }
    //return NULL;
}

bool existeSocio(string CI) {

    for (int i = 0; i < CantSocios; i++) {
        if (arreglo_socios[i] != NULL && arreglo_socios[i]->getCI().compare(CI) == 0) {
            return true;
        }
    }
    return false;
}


DtSocio** obtenerInfoSociosPorClase(int idClase, int& cantSocios) {
    cantSocios=0;
    Clase* clase = NULL;

    for (int i = 0; i < CantClases; i++) {
        if (arreglo_clases[i] != NULL && arreglo_clases[i]->getId() == idClase) {
            clase = arreglo_clases[i];
            break;
        }
    }

    if (clase == NULL) {
        throw invalid_argument("La clase no existe");
    }

    Entrenamiento* entrenamiento = dynamic_cast<Entrenamiento*> (clase);

    int cupos = 0;

    if (entrenamiento != NULL) {
        cupos = entrenamiento->cupo();
    } else {
        Spinning* spinning = dynamic_cast<Spinning*> (clase);

        cupos = spinning->cupo();
    }

    Inscripcion** inscripciones = clase->getInscripcion();


    for (int i = 0; i < cupos; i++) {
        if (inscripciones[i] != NULL) {
            cantSocios++;
        }
    }



    DtSocio** resultado = (DtSocio**) malloc(sizeof (DtSocio) * cantSocios);
    int pos = 0;

    for (int i = 0; i < cupos; i++) {
        if (inscripciones[i] != NULL) {
            Socio* socio = inscripciones[i]->getSocio();
            resultado[pos] = new DtSocio(socio->getCI(), socio->getNombre());
        }
        pos++;
    }

    return resultado;
}

